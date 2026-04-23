#include "vector.h"
#include <stdlib.h>
#include <string.h>

// ========== Utilities ==========
static void* getaddr(vector* vec, size_t idx) {
    return (char*)vec->data + (idx * vec->elem_size);
}
size_t veclen(vector* vec) {
    if (!vec || !vec->data || vec->size == 0) return 0;

    return vec->size;
}

// ========== Memory control ==========
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

// ========== Elements control ==========
void vassign(vector* dest, void* src_start, void* src_end) {
    if (!dest || !src_start || !src_end) return;

    size_t src_size = (char*)src_end - (char*)src_start;
    size_t items_count = src_size / dest->elem_size;
    
    if (items_count > dest->capacity) {
        void* temp = realloc(dest->data, items_count * dest->elem_size);
        if (!temp) return;

        dest->data = temp;
        dest->capacity = items_count;
    }

    memcpy(dest->data, src_start, src_size);
    
    dest->size = items_count;
}

// ========== Elements access ==========
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
void* vbegin(vector* vec) {
    if (!vec || !vec->data) return NULL;

    return vec->data; 
}
void* vend(vector* vec) {
    if (!vec || !vec->data) return NULL;

    return (char*)vec->data + (vec->size * vec->elem_size);
}
