#include "avector.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ========== Utilities ==========
static void* getaddr(vector* vec, size_t idx) {
    return (char*)vec->data + (idx * vec->elem_size);
}
size_t vsize(vector* vec) {
    if (!vec || !vec->data || vec->size == 0) return 0;

    return vec->size;
}
size_t vcapacity(vector* vec) {
    if (!vec || !vec->data || vec->capacity == 0) return 0;

    return vec->capacity;
}
bool vempty(vector* vec) {
    if (vec->size != 0)
        return false;

    return true;
}
size_t vmax_size(vector* vec) {
    if (!vec || vec->size == 0 || vec->capacity == 0) return 0;

    return vec->capacity;
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
void vreserve(vector* vec, size_t size) {
    if (!vec || vec->capacity > size) return;

    size_t newCapacity = (vec->capacity == 0) ? size : vec->capacity + size;

    void* temp = realloc(vec->data, newCapacity * vec->elem_size);
    if (temp == NULL) return;

    vec->data = temp;
    vec->capacity = newCapacity;

}
void vresize(vector* vec, size_t n) {
    if (!vec) return;

    if (n < vec->size) {
        vec->size = n;
        return;
    }

    if (n > vec->size) {
        if (n > vec->capacity) {
            size_t newCapacity = (vec->capacity == 0) ? n : vec->capacity;
            while (newCapacity < n) newCapacity *= 2;

            void* temp = realloc(vec->data, newCapacity * vec->elem_size);
            if (temp == NULL) return;

            vec->data = temp;
            vec->capacity = newCapacity;
        }

        char* base = (char*)vec->data;
        char* newElemStart = base + (vec->size * vec->elem_size);

        size_t newBytesToAdd = (n - vec->size) * vec->elem_size;

        memset(newElemStart, 0, newBytesToAdd);

        vec->size = n;
    }
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
void vpush_back(vector* vec, void* data) {
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
void vpop_back(vector* vec) {
    if (!vec || !vec->data) return;

    vec->size--;
}
void vclear(vector* vec) {
    if (vec->size == 0 || vec->capacity == 0) return;

    while (vec->size != 0)
        vpop_back(vec);
}
vector* verase(vector* vec, size_t first, size_t last) {
    if (vec->size == 0 || vec->capacity == 0) return NULL;
    if (first > vec->size) return NULL;
    if (last == 0) return 0;

    for (size_t i = first; i <= last; i++) {
        vec[i].data = NULL;
        vec->size--;
    }

    return vec;
}
void vinsert(vector* vec, size_t pos, void* elem) {
    if (!vec || !elem || pos > vec->size) return;

    if (vec->size == vec->capacity) {
        size_t newCapacity = (vec->capacity == 0) ? 1 : vec->capacity * 2;

        void* temp = realloc(vec->data, newCapacity * vec->elem_size);
        if (temp == NULL) return;

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
}

// ========== Elements access ==========
void* vdata(vector* vec) {
    if (vec->size == 0 || vec->capacity == 0 || vec->data == 0) return NULL;

    return vec->data;
}
void* vbegin(vector* vec) {
    if (!vec || !vec->data) return NULL;

    return vdata(vec);
}
void* vend(vector* vec) {
    if (!vec || !vec->data) return NULL;

    return (char*)vec->data + (vec->size * vec->elem_size);
}
void* vfront(vector* vec) {
    void** data = vdata(vec);

    return data[0];
}
