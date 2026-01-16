#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "hash_table.h"
#include "my_utils.h"

#define P 157

HashTable *create_hash_table(int buckets_size) {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    check_initialization(table, "Failed to allocate memory for hash table");
    table->buckets_size = buckets_size;
    table->buckets = (Node **)calloc(buckets_size, sizeof(Node *));
    check_initialization_eventually_free(table->buckets, table, "Failed to allocate memory for hash table buckets");
    return table;
}

static uint_fast32_t hash_function(const char *gram, const int buckets_size) {
    uint_fast32_t hash_value = 0;
    while (*gram) {
        unsigned char c = (unsigned char)*gram;
        hash_value = (hash_value * P + c) % buckets_size; // thanks to the distributive property of the module operation
        gram++;
    }
    return hash_value;
}

void add_gram(HashTable *table, const char *gram) {
    uint_fast32_t index = hash_function(gram, table->buckets_size);
    // if the gram is present, increment its counter.
    Node *current_node = table->buckets[index];
    while (current_node) {
        if (strcmp(current_node->gram, gram) == 0) {
            current_node->counter++;
            return;
        }
        current_node = current_node->next;
    }
    // althought create new node and insert it in the head of its related open chain.
    Node *new_node = (Node *)malloc(sizeof(Node));
    check_initialization(new_node, "Failed to allocate memory for new node");
    new_node->gram = strdup(gram);
    check_initialization_eventually_free(new_node->gram, new_node, "Failed to initialize new node gram");
    new_node->counter = 1;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

void free_hash_table(HashTable *table) {
    check_ptr(table, "Hash table pointer is NULL");
    for (int i=0; i < table->buckets_size; i++) {
        Node *current_node = table->buckets[i];
        while (current_node) {
            // the next node will be free in the next iteration
            Node *temp = current_node;
            current_node = current_node->next;
            free(temp->gram);
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}