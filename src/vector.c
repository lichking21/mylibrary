#include "vector.h"
#include <stdlib.h>
#include <string.h>

// ========== Utilities ==========
static void* getaddr(vector* vec, size_t idx) {
    return (char*)vec->data + (idx * vec->elem_size);
}

// ========== Memory management ==========
vector* vecnew(size_t elem_size, size_t init_capacity) {
    vector* vec = (vector*)malloc(sizeof(vector));
    if (!vec) return NULL;

    size_t capacity = (init_capacity == 0) ? 16 : init_capacity;

    vec->data = malloc(capacity * elem_size); 
    if (!vec->data) return NULL;

    vec->size = 0;
    vec->capacity = capacity;
    vec->elem_size = elem_size;

    return vec;
}
void vecfree(vector* vec) {
    if (!vec) return;

    free(vec->data);

    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
    vec->elem_size = 0;

    free(vec);
}

// ========== Capacity & Size ==========
void vpushback(vector* vec, void* data) {
    if (!vec || !data) return;

    if (vec->size + 1 > vec->capacity) {
        size_t new_capacity = (vec->capacity == 0) ? 16 : vec->capacity * 2;

        void* temp = realloc(vec->data, new_capacity * vec->elem_size);
        if (!temp) return;

        vec->data = temp;
        vec->capacity = new_capacity;
    }

    size_t last_elem = vec->size;
    void* addr = getaddr(vec, last_elem);

    memcpy(addr, data, vec->elem_size);
    vec->size++;
}
void vpopback(vector* vec) {
    if (!vec || !vec->data) return;

    vec->size--;
}