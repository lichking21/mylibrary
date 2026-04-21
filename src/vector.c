#include "vector.h"
#include <stdlib.h>

// ========== Memory management ==========
vector* vecnew(size_t elem_size, size_t init_capacity) {
    vector* vec = (vector*)malloc(sizeof(vector));
    if (!vec) return NULL;

    size_t capacity = (init_capacity == 0) ? 8 : init_capacity;

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