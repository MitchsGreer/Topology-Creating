
echo "Importing data..."
knn run import \
--input "test_data/small_test_data.txt" \
--output "test_data/small_test_data.emx" \
--nan "NA" \
--samples 0

echo "Calculating distances..."
knn run calc \
--in "test_data/small_test_data.emx" \
--out "test_data/small_test_data.trm"

echo "Creating knn table..."
knn run stitch \
--in "test_data/small_test_data.trm" \
--out "test_data/small_test_data.knn"

echo "Exporting knn..."
knn run export-knn \
--in "test_data/small_test_data.knn" \
--distout "test_data/small_test_data_dist.txt" \
--indiciesout "test_data/small_test_data_ind.txt"