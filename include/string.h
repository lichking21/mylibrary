#ifndef STRING_H
#define STRING_H
#include <stddef.h>

typedef struct 
{
    char* data;
    size_t size;
    size_t capacity;

}string;

// Constructor & Destructor
string* string_new(const char*);
void string_free(string*);

// Resize


#endif