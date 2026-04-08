#include <stdlib.h>
#include <stddef.h>
#include "astring.h"

// Memory management
string* strnew(const char* s) {
    string* str = malloc(sizeof(string));
    if (str == NULL) 
        return NULL;
        
    size_t size = cstrlength(s);
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
static size_t strlen_raw(const char* s) {
    size_t len = 0;
    while (*s != '\0') {
        len++;
        s++;
    }
    
    return len;
}
static char* append_raw(char* str1, const char* str2) {
    int len1 = cstrlength(str1);
    int len2 = cstrlength(str2);

    char* temp = (char*)realloc(str1, len1+len2+1);
    if (temp == NULL)
        return str1;

    str1 = temp;

    for (int i = 0; i < len2; i++)
        str1[len1 + i] = str2[i];
    
    str1[len1 + len2] = '\0';

    return str1;
}

size_t cstrlength(const char* s) {
    return strlen_raw(s);
}
size_t strlength(string* s) {
    return strlen_raw(s->data);
}

string* cstrappend(char* s1, char* s2) {
    if (s1 == NULL || s2 == NULL)
        return NULL;

    char* new_str = append_raw(s1, s2);
    if (new_str == NULL) return NULL;

    string* res = (string*)malloc(sizeof(string));
    if (res == NULL) return NULL;

    res->data = new_str;
    res->size = cstrlength(new_str);
    res->capacity = res->size + 1;

    return res;
}
string* strappend(string* s1, string* s2) {
    if (s1 == NULL || s2 == NULL)
        return NULL;

    char* new_str = append_raw(s1->data, s2->data);
    if (new_str == NULL) return NULL;

    s1->data = new_str;
    s1->size = s1->size + s2->size;
    s1->capacity = s1->size + 1;

    return s1;
}