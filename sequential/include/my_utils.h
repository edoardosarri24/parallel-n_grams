#ifndef MY_UTILS_H
#define MY_UTILS_H

// checks if a pointer is nullptr (memory allocation error).
void check_initialization(void *ptr, const char *msg);

// checks if a pointer is nullptr (memory allocation error) and frees the initialized pointer.
void check_initialization_eventually_free(void *ptr, void *to_free, const char *msg);

// checks if a pointer is nullptr (logical error).
void check_ptr(void *ptr, const char *msg);

#endif // MY_UTILS_H
