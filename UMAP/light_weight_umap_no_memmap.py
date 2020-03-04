print("---Load Modules---")
import numpy as np
import pandas as pd
import xarray as xr
import umap as mp
import hdbscan
from sklearn.preprocessing import quantile_transform
from boruta import boruta_py
from sklearn.ensemble import RandomForestClassifier
import holoviews as hv
import datashader as ds
import datashader.transfer_functions as tf
from datashader.layout import random_layout, circular_layout, forceatlas2_layout
from datashader.bundling import connect_edges, hammer_bundle
import holoviews.operation.datashader as hd
import networkx as nx
import matplotlib.pyplot as plt
from tempfile import mkdtemp
import os.path as path
hv.extension('bokeh')
print("---Load Done---")


#init the input file
print("---Init Files---")
#index files
index_input_filename = "/home/mitchell/scidas/mitchell/knn_results/ind.txt"
index_file = "index.dat"

#distance files
distance_input_filename = "/home/mitchell/scidas/mitchell/knn_results/dist.txt"
distance_file = "distance.dat"

#GEM file
gem_input_file = "rice_heat_drought.GEM.hisat2.FPKM.log2.txt"

#BioDeepVis files
edge_filename = "umap.tab"
node_filename = "umap.tab.cluster"

index_input_file = open(index_input_filename, "r")
distance_input_file = open(distance_input_filename, "r")

size = 0
for line in distance_input_file:
    size += 1

distance_input_file.seek(0)
print("Lines:", size)

# #init the memmap
# index = np.memmap(index_file, dtype='float32', mode='w+', shape=(size,size))
# distance = np.memmap(distance_file, dtype='float32', mode='w+', shape=(size,size))
print("---Init Done---")

# #read each line from the file into the memmap
# print("---Load ind/dist---")
# for line_number in range(size):
#     print("%.2f" % ((line_number/size) * 100), "%", end="\r")

#     #grab the info for the index
#     index_writing_workspace = np.array(index_input_file.readline().split("\t"))
#     index_writing_workspace = index_writing_workspace[:size]
#     index[line_number:size] = index_writing_workspace[:size]

#     #grab the info for the distance
#     distance_writing_workspace = np.array(distance_input_file.readline().split("\t"))
#     distance_writing_workspace = distance_writing_workspace[:size]
#     distance[line_number:size] = distance_writing_workspace[:size]
    
#     del index
#     del distance
    
#     index = np.memmap(index_file, dtype='float32', mode='r+', shape=(size,size))
#     distance = np.memmap(distance_file, dtype='float32', mode='r+', shape=(size,size))
# print()
# print("---Load Done---")


index = pd.read_csv(index_input_filename, sep="\t")
distance = pd.read_csv(distance_input_filename, sep="\t")

print("---Load GEM---")
gem_df = pd.read_csv(gem_input_file, index_col=0, sep='\t').apply(np.exp2).fillna(0).T
# Declare an index name so it matches the (future) label data frame.
gem_df.index.rename('Sample')
gem_df = gem_df.transpose()
print("---Load Done---")

#run Umap
print("---Start UMAP---")
test = mp.umap_.fuzzy_simplicial_set(X=gem_df.values, 
                                     n_neighbors=size-1, 
                                     knn_indices=index.values, 
                                     knn_dists=distance.values,
                                     random_state=np.random.RandomState(1), 
                                     metric="manhattan", 
                                     verbose=True)
print("---UMAP Done---")

# #Print edges and nodes to files
# print("---Write Edges and Nodes---")
# edge_file = open(edge_filename, "w")
# node_file = open(node_filename, "w")

# nodes = []

# size = len(list(test.todok().items()))
# line_number = 0

# for item in list(test.todok().items()):
#     string = str(item[0][0]) + str("\t") + str(item[0][1]) + "\n"
#     edge_file.write(string)
#     if item[0][0] not in nodes:
#         nodes.append(item[0][0])
#         string = str(item[0][0]) + str("\t") + str(1) + "\n"
#         node_file.write(string)
#     print("%.2f" % ((line_number/size) * 100), "%", end="\r")
#     line_number += 1
# print()

# edge_file.close()
# node_file.close()
# print("---Write Done---")

fuzzy_df = pd.DataFrame(test.todense())
fuzzy_df.shape

label_df = pd.read_csv("PRJNA301554.hydroponic.sample_annotations.txt", index_col=0, sep='\t')
labels = label_df.astype('object').reset_index()

fuzzy_edges = pd.DataFrame(fuzzy_df.stack()).reset_index()
fuzzy_edges.columns = ['source', 'target', 'weight']
fuzzy_edges.head(2)

cutoff = fuzzy_edges['weight'].quantile(.95)
filtered = fuzzy_edges[fuzzy_edges['weight'] > cutoff]
print(f'Cutoff: {cutoff:.3}')
print(f'Remaining shape: {filtered.shape}')

atlas_layout = forceatlas2_layout(labels, fuzzy_edges, iterations=100)

hv_opts = {}
hv_opts['padding'] = 0.1
hv_opts['width'] = 600
hv_opts['height'] = 400
hv_opts['cmap'] = 'Set1'
hv_opts['xaxis'] = None
hv_opts['yaxis'] = None
hv_opts['size'] = 5


vdims = ['Sample', 'Treatment', 'Genotype', 'Subspecies', 'Time']
hv_nodes = hv.Nodes(atlas_layout, kdims=['x', 'y', 'index'], vdims=vdims)
hv_nodes.opts(**hv_opts)
