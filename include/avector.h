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
void vreserve(vector*, size_t);
void vresize(vector*, size_t elemsNum);

// ========== Utilities ==========
size_t vsize(vector*);
size_t vcapacity(vector*);
bool vempty(vector*);
size_t vmax_size(vector*);

// ========== Elements control ==========
void vassign(vector*, void*, void*);
void vpush_back(vector*, void*);
void vpop_back(vector*);
void vclear(vector*);
vector* verase(vector*, size_t, size_t);
void vinsert(vector*, size_t, void*);

// ========== Elements access ==========
void* vdata(vector*);
void* vbegin(vector*);
void* vend(vector*);
void* vfront(vector*);

#endif
