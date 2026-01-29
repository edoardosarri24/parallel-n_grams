#ifndef ARENA_H
#define ARENA_H

#include <stddef.h>

typedef struct Arena Arena;

Arena *create_arena(size_t default_block_size);
void *arena_alloc(Arena *arena, size_t requested_size);
void arena_connect(Arena *dest, Arena *src);
void arena_free(Arena *arena);

#endif // ARENA_H
