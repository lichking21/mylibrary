#ifndef ASTRING_H
#define ASTRING_H
#include <stddef.h>

typedef struct 
{
    char* data;
    size_t size;
    size_t capacity;

}string;

// Memory management
string* strnew(const char*);
void strfree(string*);

// Capacity & Size
size_t length(string*);

void append(string*, const string*);

void pushback(string*, char);
void popback(string*);

void clear(string*);

int empty(const string*);

// Elements accesess
const char* at(const string*, size_t);

const char* back(const string*);
const char* begin(const string*);
const char* end(const string*);

size_t copy(string*, char*, size_t, size_t);

int compareall(const string*, const string*);
int compare(string*, size_t, size_t, string*);

#endif