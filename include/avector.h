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
vector* avec_new(size_t, size_t);
void avec_free(vector*);
int avec_reserve(vector*, size_t);
int avec_resize(vector*, size_t elemsNum);

// ========== Utilities ==========
size_t avec_size(vector*);
size_t avec_capacity(vector*);
bool avec_empty(vector*);
size_t avec_max_size(vector*);

// ========== Elements control ==========
int avec_assign(vector*, void*, void*);
int avec_push_back(vector*, void*);
void avec_pop_back(vector*);
void avec_clear(vector*);
vector* avec_erase(vector*, size_t, size_t);
int avec_insert(vector*, size_t, void*);
void avec_swap(vector*, vector*);

// ========== Elements access ==========
void* avec_data(vector*);
void* avec_begin(vector*);
void* avec_end(vector*);
void* avec_front(vector*);

#endif
