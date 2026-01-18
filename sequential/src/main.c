#include <stdlib.h>
#include "hash_table.h"
#include "helper_functions.h"
#include "statistics.h"
#include "my_utils.h"

#define HASH_TABLE_DIMENSION 150000

int main() {
    // pre-processing
    printf("Pre-processing the input file...\n");
    preprocess_file();

    // count the N-gram.
    printf("Count the %d-gram...\n", N_GRAM_SIZE);
    FILE *src = fopen(DATA_DIR"/normalized_text.txt", "r");
    check_initialization(src, "Error opening input normalized file");
    HashTable *hashTable = create_hash_table(HASH_TABLE_DIMENSION);
    char *gram;
    char temp_buffer[256];
    while ((gram = next_ngram(src)) != NULL) {
        printf("%s\n", gram);
        add_gram(hashTable, gram);
        free(gram);
        for(int i=0; i<STRIDE; i++)
            fscanf(src, "%255s", temp_buffer);
    }
    fclose(src);

    // visualize statistics
    print_text_statistics(hashTable);
    printf("-----------------------\n");
    print_hashtable_statistics(hashTable);

    // close
    free_hash_table(hashTable);
    return EXIT_SUCCESS;
}