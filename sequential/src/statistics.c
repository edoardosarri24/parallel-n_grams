#include <stdio.h>
#include <stdlib.h>
#include "statistics.h"
#include "hash_table.h"
#include "my_utils.h"

static int compare_nodes(const void *a, const void *b) {
    const Node *nodeA = *(const Node **)a;
    const Node *nodeB = *(const Node **)b;
    // Descending order
    return (nodeB->counter - nodeA->counter);
}

static size_t count_unique_ngrams(HashTable *hashTable) {
    size_t count = 0;
    for (int i=0; i < hashTable->buckets_size; ++i) {
        Node *current = hashTable->buckets[i];
        while (current) {
            count++;
            current = current->next;
        }
    }
    return count;
}

void get_text_statistics(HashTable *hashTable) {
    check_ptr(hashTable, "get_text_statistics in statistics.c received NULL hashTable");
    // Count the unique n-grams
    const size_t unique_ngrams = count_unique_ngrams(hashTable);
    if (unique_ngrams == 0) {
        printf("No n-grams found.\n");
        return;
    }
    // Define, populate and sort the temporary array
    Node **unique_ngrams_array = malloc(unique_ngrams * sizeof(Node *));
    check_initialization(unique_ngrams_array, "Failed to allocate unique_ngrams_array");
    size_t node_array_index = 0;
    for (int i=0; i < hashTable->buckets_size; ++i) {
        Node *current = hashTable->buckets[i];
        while (current) {
            unique_ngrams_array[node_array_index++] = current;
            current = current->next;
        }
    }
    qsort(unique_ngrams_array, unique_ngrams, sizeof(Node *), compare_nodes);
    // Print statistics
    printf("Total unique n-grams: %zu\n", unique_ngrams);
    printf("Top %d n-grams:\n", TOP_K);
    int limit = (unique_ngrams < TOP_K) ? (int)unique_ngrams : TOP_K;
    for (int i=0; i < limit; ++i) {
        printf("%d - '%s': %d\n", i+1, unique_ngrams_array[i]->gram, unique_ngrams_array[i]->counter);
    }
    // free the memory
    free(unique_ngrams_array);
}

void get_hashtable_statistics(HashTable *hashTable) {
    //TODO
}