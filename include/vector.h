#ifndef VECTOR_H
#define VECTOR_H
#include <stddef.h>

typedef struct {
    void* data;
    size_t size;
    size_t capacity;
    size_t elem_size;
}vector;

vector* vecnew(size_t, size_t);

#endif