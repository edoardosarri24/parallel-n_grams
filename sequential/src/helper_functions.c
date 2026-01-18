#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "helper_functions.h"
#include "my_utils.h"

void preprocess_file() {
    // open source and destination.
    const char *input_path = DATA_DIR"/input.txt";
    FILE *src = fopen(input_path, "r");
    check_initialization(src, "Error opening input file. The file MUST be named input.txt and MUST be in data directory.\n");
    const char *output_path = DATA_DIR"/normalized_text.txt";
    FILE *dst = fopen(output_path, "w");
    check_initialization_eventually_free(dst, src, "Error opening output file");
    // pre-processing.
    int c;
    bool have_to_insert_space = false; // write only one single space.
    bool is_first_word = true; // don't include space at the beginning.
    while ((c = fgetc(src)) != EOF) {
        if (!isspace(c) && !ispunct(c)) { // ignore tha spaces and the puntation.
            if (have_to_insert_space && !is_first_word) { // insert a space only if we already write something and we haven't write a space.
                fputc(' ', dst);
                have_to_insert_space = false;
            }
            fputc(tolower(c), dst);
            is_first_word = false;
            have_to_insert_space = false;
        } else {
            have_to_insert_space = true;
        }
    }
    // close the source and destination.
    fclose(dst);
    fclose(src);
}

char *next_ngram(FILE *src) {
    // variables.
    char words[N_GRAM_SIZE][256];
    char *ngram = (char *)malloc(N_GRAM_SIZE * 256 * sizeof(char));
    check_initialization(ngram, "Error allocating memory for ngram.\n");
    long start_position = ftell(src);
    // save the words of the next ngram.
    for (int i=0; i<N_GRAM_SIZE; i++) {
        if (fscanf(src, "%255s", words[i]) != 1) {
            free(ngram);
            return NULL;
        }
    }
    // compose the next ngrams.
    int offset = 0;
    for (int i = 0; i < N_GRAM_SIZE; i++) {
        offset += sprintf(ngram + offset, "%s%s", words[i], (i == N_GRAM_SIZE - 1) ? "" : " ");
    }
    // come back to the original file poitner position.
    fseek(src, start_position, SEEK_SET);
    return ngram;
}