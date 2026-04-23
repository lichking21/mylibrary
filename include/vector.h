#ifndef VECTOR_H
#define VECTOR_H
#include <stddef.h>

typedef struct {
    void* data;
    size_t size;
    size_t capacity;
    size_t elem_size;
}vector;

// ========== Memory control ==========
vector* vecnew(size_t, size_t);
void vecfree(vector*);

// ========== Utilities ==========
size_t veclen(vector*);

// ========== Elements control ==========
void vassign(vector*, void*, void*);

// ========== Elements access ==========
void vpushback(vector*, void*);
void vpopback(vector*);
void* vbegin(vector*);
void* vend(vector*);

#endif