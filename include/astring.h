#ifndef ASTRING_H
#define ASTRING_H
#include <stddef.h>

typedef struct
{
    char* data;
    size_t size;
    size_t capacity;

}string;

// ========== Memory management
string* astr_new(const char*);
void astr_free(string*);

// ========== Capacity & Size
size_t astr_length(string*);
int astr_resize(string*, size_t);
int astr_append(string*, const string*);
string* astr_insert(string*, const char*, size_t pos);
int astr_push_back(string*, char);
void astr_pop_back(string*);
void astr_clear(string*);
int astr_empty(const string*);
string* astr_erase(string*, size_t pos, size_t len);

// ========== Elements accesess
const char* astr_at(const string*, size_t);
const char* astr_back(const string*);
const char* astr_begin(const string*);
const char* astr_end(const string*);
size_t astr_copy(string*, char*, size_t, size_t);
int astr_comparea_ll(const string*, const string*);
int astr_compare(const string*, size_t, size_t, const string*);
size_t astr_find(const string*, const string*);
size_t astr_rfind(const string*, const string*);
string* astr_substr(const string*, size_t, size_t);
string* astr_replace(string*, size_t, size_t, const string*);
void astr_swap(const string*, const string*);

#endif
