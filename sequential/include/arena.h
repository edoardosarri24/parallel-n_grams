#ifndef ARENA_H
#define ARENA_H

#include <stddef.h>

typedef struct Arena Arena;

// creates a new memory arena.
Arena *create_arena(size_t default_block_size);

// allocations.
void *arena_alloc(Arena *arena, size_t requested_size);

// Frees all memory associated with the arena.
void arena_free(Arena *arena);

// Returns the total memory usage of the arena in bytes.
size_t arena_get_memory_usage(Arena *arena);

#endif // ARENA_H