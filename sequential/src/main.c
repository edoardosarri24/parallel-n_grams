#include <stdlib.h>
#include <omp.h>
#include "hash_table.h"
#include "helper_functions.h"
#include "statistics.h"
#include "my_utils.h"

int main() {
    // time measurement start
    double start_time = omp_get_wtime();

    // pre-processing
    double start_time_preprocessing = omp_get_wtime();
    const char *input_filepath = DATA_DIR"/input.txt";
    const char *normalized_filepath = DATA_DIR"/normalized_input.txt";
    preprocess_file(input_filepath, normalized_filepath);
    double end_time_preprocessing = omp_get_wtime();

    // populate the hash table.
    double start_time_populate = omp_get_wtime();
    HashTable *hashTable = populate_hashtable(normalized_filepath);
    double end_time_populate = omp_get_wtime();

    // visualize statistics
    double start_time_statistics = omp_get_wtime();
    printf("\n----- TEXT STATISTICS -----\n");
    print_text_statistics(hashTable);
    printf("\n----- HASHTABLE STATISTICS -----\n");
    print_hashtable_statistics(hashTable);
    double end_time_statistics = omp_get_wtime();

    // close
    free_hash_table(hashTable);

    // time measurement end
    double end_time = omp_get_wtime();
    printf("\n----- TIME STATISTICS -----\n");
    printf("Total execution time: %.4f seconds\n", end_time - start_time);
    printf("Pre-processing time: %.4f seconds\n", end_time_preprocessing - start_time_preprocessing);
    printf("Populate hashtable time: %.4f seconds\n", end_time_populate - start_time_populate);
    printf("Statistics time: %.4f seconds\n", end_time_statistics - start_time_statistics);

    return EXIT_SUCCESS;
}