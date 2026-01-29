#include <stdlib.h>
#include <stdio.h>
#include "my_utils.h"

void check_initialization(void *ptr, const char *msg) {
    if (!ptr) {
        perror(msg);
        exit(EXIT_FAILURE);
    }
}

void check_initialization_eventually_free(void *ptr, void *to_free, const char *msg) {
    if (!ptr) {
        perror(msg);
        free(to_free);
        exit(EXIT_FAILURE);
    }
}

void check_ptr(void *ptr, const char *msg) {
    if (!ptr) {
        fprintf(stderr, "Error: %s\n", msg);
        exit(EXIT_FAILURE);
    }
}
