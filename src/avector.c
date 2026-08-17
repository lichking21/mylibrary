#include "avector.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

// ========== Utilities ==========
static void* getaddr(vector* vec, size_t idx) {
    return (char*)vec->data + (idx * vec->elem_size);
}
size_t avec_size(vector* vec) {
    assert(vec != NULL && vec->data != NULL);
    if (vec == NULL) return 0;

    return vec->size;
}
size_t avec_capacity(vector* vec) {
    assert(vec != NULL && vec->data != NULL);
    if (vec == NULL) return 0;

    return vec->capacity;
}
bool avec_empty(vector* vec) {
    assert(vec != NULL && vec->data != NULL);
    if (vec == NULL) return true;

    return vec->size == 0;
}
size_t avec_max_size(vector* vec) {
    assert(vec != NULL && vec->data != NULL);
    if (vec == NULL) return 0;

    return vec->capacity;
}

// ========== Memory control ==========
vector* avec_new(size_t elem_size, size_t init_capacity) {
    vector* vec = (vector*)malloc(sizeof(vector));
    if (!vec) return NULL;

    size_t capacity = (init_capacity == 0) ? 16 : init_capacity;

    vec->data = malloc(capacity * elem_size);
    if (!vec->data) {
        free(vec);
        return NULL;
    }

    vec->size = 0;
    vec->capacity = capacity;
    vec->elem_size = elem_size;

    return vec;
}
void avec_free(vector* vec) {
    if (vec == NULL) return;

    if (vec->data != NULL) {
        free(vec->data);
        vec->data = NULL;
    }

    vec->size = 0;
    vec->capacity = 0;
    vec->elem_size = 0;

    free(vec);
}
int avec_reserve(vector* vec, size_t size) {
    assert(vec != NULL && vec->data != NULL);
    if (vec == NULL || vec->data == NULL) return 0;
    if (size <= vec->capacity) return 1;

    void* temp = realloc(vec->data, size * vec->elem_size);
    if (temp == NULL) return 0;

    vec->data = temp;
    vec->capacity = size;

    return 1;
}
int avec_resize(vector* vec, size_t n) {
    assert(vec != NULL && vec->data != NULL);
    if (vec == NULL || vec->data == NULL) return 0;

    if (n < vec->size) {
        vec->size = n;
        return 1;
    }

    if (n > vec->size) {
        if (n > vec->capacity) {
            size_t newCapacity = (vec->capacity == 0) ? n : vec->capacity;
            while (newCapacity < n) newCapacity *= 2;

            void* temp = realloc(vec->data, newCapacity * vec->elem_size);
            if (temp == NULL) return 0;

            vec->data = temp;
            vec->capacity = newCapacity;
        }

        char* base = (char*)vec->data;
        char* newElemStart = base + (vec->size * vec->elem_size);

        size_t newBytesToAdd = (n - vec->size) * vec->elem_size;

        memset(newElemStart, 0, newBytesToAdd);

        vec->size = n;
    }
    return 1;
}

// ========== Elements control ==========
int avec_assign(vector* dest, void* src_start, void* src_end) {
    assert(dest != NULL && dest->data != NULL && src_start != NULL && src_end != NULL && src_start <= src_end);
    if (dest == NULL || dest->data == NULL || src_start == NULL || src_end == NULL || src_start > src_end) return 0;

    size_t src_size = (char*)src_end - (char*)src_start;
    size_t items_count = src_size / dest->elem_size;

    if (items_count > dest->capacity) {
        void* temp = realloc(dest->data, items_count * dest->elem_size);
        if (!temp) return 0;

        dest->data = temp;
        dest->capacity = items_count;
    }

    memcpy(dest->data, src_start, src_size);

    dest->size = items_count;

    return 1;
}
int avec_push_back(vector* vec, void* data) {
    assert(vec != NULL && vec->data != NULL && data != NULL);
    if (vec == NULL || vec->data == NULL || data == NULL) return 0;

    if (vec->size + 1 > vec->capacity) {
        size_t new_capacity = (vec->capacity == 0) ? 16 : vec->capacity * 2;

        void* temp = realloc(vec->data, new_capacity * vec->elem_size);
        if (!temp) return 0;

        vec->data = temp;
        vec->capacity = new_capacity;
    }

    size_t last_elem = vec->size;
    void* addr = getaddr(vec, last_elem);

    memcpy(addr, data, vec->elem_size);
    vec->size++;

    return 1;
}
void avec_pop_back(vector* vec) {
    assert(vec != NULL && vec->data != NULL && vec->size > 0);
    if (vec == NULL || vec->data == NULL || vec->size == 0) return;

    vec->size--;
}
void avec_clear(vector* vec) {
    assert(vec != NULL && vec->data != NULL);
    if (vec == NULL || vec->data == NULL) return;

    while (vec->size != 0)
        avec_pop_back(vec);
}
void vclear(vector* vec) {
    avec_clear(vec);
}
vector* avec_erase(vector* vec, size_t first, size_t last) {
    assert(vec != NULL && vec->data != NULL);
    if (vec == NULL || vec->data == NULL) return vec;

    if (first >= vec->size || first >= last) return vec;
    if (last > vec->size)    last = vec->size;

    char* base = (char*)vec->data;
    char* dest = base + (first * vec->elem_size);
    char* src = base + (last * vec->elem_size);

    size_t elemsToMove = vec->size - last;
    size_t bytesToMove = elemsToMove * vec->elem_size;

    if (bytesToMove > 0)
        memmove(dest, src, bytesToMove);

    vec->size -= (last - first);

    return vec;
}
int avec_insert(vector* vec, size_t pos, void* elem) {
    assert(vec != NULL && vec->data != NULL && elem != NULL && pos <= vec->size);
    if (vec == NULL || vec->data == NULL || elem == NULL || pos > vec->size) return 0;

    if (vec->size == vec->capacity) {
        size_t newCapacity = (vec->capacity == 0) ? 1 : vec->capacity * 2;

        void* temp = realloc(vec->data, newCapacity * vec->elem_size);
        if (temp == NULL) return 0;

        vec->data = temp;
        vec->capacity = newCapacity;
    }

    char* base = (char*)vec->data;
    char* dest = base + (pos * vec->elem_size);

    if (pos < vec->size) {
        char* tail = base + ((pos + 1) * vec->elem_size);
        size_t itemsToMove = vec->size - pos;

        memmove(tail, dest, itemsToMove * vec->elem_size);
    }

    memcpy(dest, elem, vec->elem_size);

    vec->size++;

    return 1;
}
void avec_swap(vector* vec, vector* x) {
    assert(vec != NULL && vec->data != NULL && x != NULL && x->data != NULL);
    if (vec == NULL || vec->data == NULL || x == NULL || x->data == NULL) return;

    vector temp = *vec;
    *vec = *x;
    *x = temp;
}

// ========== Elements access ==========
void* avec_data(vector* vec) {
    assert(vec != NULL && vec->data != NULL);
    if (vec == NULL) return NULL;

    return vec->data;
}
void* avec_begin(vector* vec) {
    assert(vec != NULL && vec->data != NULL);
    if (vec == NULL) return NULL;

    return avec_data(vec);
}
void* avec_end(vector* vec) {
    assert(vec != NULL && vec->data != NULL);
    if (vec == NULL) return NULL;

    return (char*)vec->data + (vec->size * vec->elem_size);
}
void* avec_front(vector* vec) {
    assert(vec != NULL && vec->data != NULL && vec->size > 0);
    if (vec == NULL || vec->data == NULL || vec->size == 0) return NULL;

    void** data = (void**)avec_data(vec);

    return data[0];
}