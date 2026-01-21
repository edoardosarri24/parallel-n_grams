#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <stdio.h>
#include "hash_table.h"

void preprocess_file(const char *input_filepath, const char *output_filepath);
HashTable* populate_hashtable(const char *filename);

#endif // HELPER_FUNCTIONS_H