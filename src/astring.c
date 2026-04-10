#include <stdlib.h>
#include <stddef.h>
#include <string.h>
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
static char* append_raw(char* str1, size_t len1, const char* str2, size_t len2) {
    char* temp = (char*)realloc(str1, len1+len2+1);
    if (temp == NULL) return NULL;

    str1 = temp;

    for (size_t i = 0; i < len2; i++)
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

char* cstrappend(char* s1, const char* s2) {
    if (s1 == NULL || s2 == NULL) return NULL;

    return append_raw(s1, cstrlength(s1), s2, cstrlength(s2));
}
void strappend(string* s1, string* s2) {
    if (s1 == NULL || s2 == NULL) return;

    size_t len1 = strlength(s1);
    size_t len2 = strlength(s2);

    char* new_data = append_raw(s1->data, len1, s2->data, len2);
    if (new_data != NULL) {
        s1->data = new_data;
        s1->size += len2;
        s1->capacity = s1->size + 1;
    }
}

void pushback(string* s, char val) {
    if (s == NULL || s->data == NULL) return;

    if (s->size + 2 > s->capacity) {
        size_t new_capacity = (s->capacity == 0) ? 0 : s->capacity * 2;
        
        char* temp = (char*)realloc(s->data, new_capacity);
        if (temp == NULL) return;

        s->data = temp;
        s->capacity = new_capacity;
    }

    s->data[s->size] = val;
    s->size++;
    s->data[s->size] = '\0';
}
void popback(string* s) {
    if (s == NULL || s->data == NULL) return;
    
    s->size--;
    s->data[s->size] = '\0';
}

void clear(string* s) {
    if (s == NULL || s->data == NULL) return;

    while(s->size != 0)
        popback(s);
}

// Elements accesess
char* at(string* s, size_t pos) {
    if (s == NULL || s->data == NULL || pos >= s->size) return NULL;

    return &s->data[pos];
}

char* back(string* s) {
    return &s->data[s->size - 1];
}
char* begin(string* s) {
    return s->data;
}

size_t copy(string* s, char* dest, size_t len, size_t pos) {
    if (s == NULL || s->data == NULL) return 0;

    for (size_t i = 0; i < len; i++) {
        dest[i] = s->data[pos++];
    }

    dest[len] = '\0';

    return len;
}

int compareall(string* s1, string* s2) {
    if (s1 == NULL || s1->data == NULL) return -1;
    if (s2 == NULL || s2->data == NULL) return 1;

    size_t len1 = s1->size;
    size_t len2 = s2->size;
    size_t min_len = (len1 > len2) ? len2 : len1;

    int res = memcmp(s1->data, s2->data, min_len);

    if (res < 0) return -1;
    else if (res > 0) return 1;

    return 0;
}

int compare(string* s1, size_t pos, size_t len, string* s2) {
    if (s1 == NULL || s1->data == NULL) return -1;
    if (s2 == NULL || s2->data == NULL) return 1;

    if (pos > s1->size) return -1;

    size_t len1 = (pos + len > s1->size) ? (s1->size - pos) : len;
    size_t len2 = s2->size;
    size_t min_len = (len1 > len2) ? len2 : len1;

    int res = memcmp(s1->data, s2->data, min_len);

    if (res != 0) return (res < 0) ? -1 : 1;

    if (len1 < len2) return -1;
    if (len1 > len2) return 1;

    return 0;
}

