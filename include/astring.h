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

string* cstrappend(char*, char*);
string* strappend(string*, string*);

#endif