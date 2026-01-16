#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct Node {
    char *gram;
    int counter;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **buckets;
    int buckets_size; // number of index
} HashTable;

HashTable *create_hash_table(int buckets_size);
void add_gram(HashTable *table, const char *gram);
void free_hash_table(HashTable *table);

#endif // HASH_TABLE_H