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
size_t cstrlength(const char*);
size_t strlength(string*);

char* cstrappend(char*, const char*);
void strappend(string*, string*);

void pushback(string*, char);
void popback(string*);

void clear(string*);

// Elements accesess
char* at(string*, size_t);

char* back(string*);
char* begin(string*);

size_t copy(string*, char*, size_t, size_t);

int compareall(string*, string*);
int compare(string*, size_t, size_t, string*);

#endif