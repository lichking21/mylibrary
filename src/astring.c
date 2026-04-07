#include <stdlib.h>
#include <stddef.h>
#include "astring.h"

// Memory management
string* strnew(const char* s) {
    string* str = malloc(sizeof(string));
    if (str == NULL) 
        return NULL;
        
    size_t size = strlength(s);
    size_t capacity = size + 1;
    
    str->data = malloc(size + 1);
    for (size_t i = 0; i <= size; i++)
        str->data[i] = s[i];

    str->size = size;
    str->capacity = capacity;

    return str;
}

void strfree(string* s) {
    if (s == NULL)
        return;

    if (s->data != NULL) {
        free(s->data);
        s->data = NULL;
    }

    s->size = 0;
    s->capacity = 0;
    
    free(s);
}

// Capacity & Size
size_t strlength(const char* s) {
    size_t len = 0;
    while (*s != '\0') {
        len++;
        s++;
    }

    return len;
}