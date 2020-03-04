#-------------------------------------------------
#
# Project created by QtCreator 2019-05-31T08:46:33
#
#-------------------------------------------------

QT       += widgets opengl

TARGET = KNNcore
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Data_Frames/data_final_knn.cpp \
    Data_Frames/data_final_knn_iterator.cpp \
    Data_Frames/data_final_knn_model.cpp \
    Data_Frames/data_triangle_matrix.cpp \
    Data_Frames/data_triangle_matrix_iterator.cpp \
    Export_Final_KNN/export_final_knn.cpp \
    Export_Final_KNN/export_final_knn_input.cpp \
    Factories/analytic_factory.cpp \
    Factories/data_factory.cpp \
    KNN_Dist_Calc/knn_dist_calc.cpp \
    KNN_Dist_Calc/knn_dist_calc_cuda.cpp \
    KNN_Dist_Calc/knn_dist_calc_cuda_kernel.cpp \
    KNN_Dist_Calc/knn_dist_calc_cuda_worker.cpp \
    KNN_Dist_Calc/knn_dist_calc_input.cpp \
    KNN_Dist_Calc/knn_dist_calc_matrix_row.cpp \
    KNN_Dist_Calc/knn_dist_calc_sample.cpp \
    KNN_Dist_Calc/knn_dist_calc_serial.cpp \
    KNN_Row_Creator/knn_row_creator.cpp \
    KNN_Row_Creator/knn_row_creator_input.cpp \
    KNN_Row_Creator/knn_row_creator_result.cpp \
    KNN_Row_Creator/knn_row_creator_row.cpp \
    KNN_Row_Creator/knn_row_creator_serial.cpp \
    Data_Frames/data_triangle_matrix_model.cpp \
    KNN_Dist_Calc/knn_dist_calc_opencl.cpp \
    KNN_Dist_Calc/knn_dist_calc_opencl_worker.cpp \
    KNN_Dist_Calc/knn_dist_calc_opencl_kernel.cpp \
    Data_Frames/expressionmatrix.cpp \
    Data_Frames/expressionmatrix_gene.cpp \
    Data_Frames/expressionmatrix_model.cpp \
    Import_Sample_Set/importexpressionmatrix.cpp \
    Import_Sample_Set/importexpressionmatrix_input.cpp \
    Export_Sample_Set/exportexpressionmatrix.cpp \
    Export_Sample_Set/exportexpressionmatrix_input.cpp \
    KNN_Row_Creator/knn_row_creator_opencl.cpp \
    KNN_Row_Creator/knn_row_creator_opencl_worker.cpp \
    KNN_Row_Creator/knn_row_creator_opencl_kernel.cpp
    

HEADERS += \
    Data_Frames/data_final_knn.h \
    Data_Frames/data_final_knn_iterator.h \
    Data_Frames/data_final_knn_model.h \
    Data_Frames/data_triangle_matrix.h \
    Data_Frames/data_triangle_matrix_iterator.h \
    Export_Final_KNN/export_final_knn.h \
    Export_Final_KNN/export_final_knn_input.h \
    Factories/analytic_factory.h \
    Factories/data_factory.h \
    KNN_Dist_Calc/knn_dist_calc.h \
    KNN_Dist_Calc/knn_dist_calc_cuda.h \
    KNN_Dist_Calc/knn_dist_calc_cuda_kernel.h \
    KNN_Dist_Calc/knn_dist_calc_cuda_worker.h \
    KNN_Dist_Calc/knn_dist_calc_input.h \
    KNN_Dist_Calc/knn_dist_calc_matrix_row.h \
    KNN_Dist_Calc/knn_dist_calc_sample.h \
    KNN_Dist_Calc/knn_dist_calc_serial.h \
    KNN_Row_Creator/knn_row_creater.h \
    KNN_Row_Creator/knn_row_creater_input.h \
    KNN_Row_Creator/knn_row_creater_serial.h \
    KNN_Row_Creator/knn_row_creator_result.h \
    KNN_Row_Creator/knn_row_creator_row.h \
    global.h \
    Data_Frames/data_triangle_matrix_model.h \
    KNN_Dist_Calc/knn_dist_calc_opencl.h \
    KNN_Dist_Calc/knn_dist_calc_opencl_worker.h \
    KNN_Dist_Calc/knn_dist_calc_opencl_kernel.h \
    Data_Frames/expressionmatrix.h \
    Data_Frames/expressionmatrix_gene.h \
    Data_Frames/expressionmatrix_model.h \
    Import_Sample_Set/importexpressionmatrix.h \
    Import_Sample_Set/importexpressionmatrix_input.h \
    Export_Sample_Set/exportexpressionmatrix.h \
    Export_Sample_Set/exportexpressionmatrix_input.h \
    KNN_Row_Creator/knn_row_creator_opencl.h \
    KNN_Row_Creator/knn_row_creator_opencl_worker.h \
    KNN_Row_Creator/knn_row_creator_opencl_kernel.h
    
unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    .qmake.stash

QMAKE_CXXFLAGS += -Wno-ignored-attributes
