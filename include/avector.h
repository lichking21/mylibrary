#ifndef AVECTOR_H
#define AVECTOR_H
#include <stddef.h>
#include <stdbool.h>

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
size_t vsize(vector*);
size_t vcapacity(vector*);
bool vempty(vector*);

// ========== Elements control ==========
void vassign(vector*, void*, void*);
void vpushback(vector*, void*);
void vpopback(vector*);
void vclear(vector*);
vector* verase(vector*, size_t, size_t);

// ========== Elements access ==========
void* vdata(vector*);
void* vbegin(vector*);
void* vend(vector*);

#endif
