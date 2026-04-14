#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "astring.h"

#include <stdio.h>


// ========== Memory management
string* strnew(const char* s) {
    string* str = malloc(sizeof(string));
    if (str == NULL) 
        return NULL;
        
    size_t size = strlen(s);
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

// ========== Capacity & Size
size_t length(string* s) {
    size_t len = 0;
    while (*s->data != '\0') {
        len++;
        s++;
    }
    
    return len;
}
void resize(string* s, size_t new_size) {
    if (!s || !s->data || s->size == new_size) return;

    if (new_size + 1 > s->capacity) {
        size_t new_capacity = (s->capacity == 0) ? 16 : s->capacity * 2;
        if (new_capacity < new_size + 1) 
            new_capacity = new_size + 1;

        char* temp = (char*)realloc(s->data, new_capacity);
        if (!temp) return;

        s->data = temp;
        s->capacity = new_capacity;
    }
    if (new_size > s->size) 
        memset(s->data + s->size, '\0', new_size - s->size);

    s->size = new_size;
    s->data[s->size] = '\0';
}

void append(string* s1, const string* s2) {
    if (s1 == NULL || s2 == NULL) return;
    if (s2->data == NULL || s2->size == 0) return;

    size_t new_size = s1->size + s2->size;

    if (new_size + 1 > s1->capacity) {
        size_t new_capacity = (s1->capacity == 0) ? new_size + 1 : s1->capacity * 2;
        
        char* temp = (char*)realloc(s1->data, new_capacity);
        if (temp == NULL) return;

        s1->data = temp;
        s1->capacity = new_capacity;
    }

    memcpy(s1->data + s1->size, s2->data, s2->size);

    s1->size = new_size;
    s1->data[s1->size] = '\0';
}
string* insert(string* s, const char* str, size_t pos) {
    if (!s || !s->data || !str || pos > s->size) return NULL;

    size_t new_size = s->size + strlen(str);
    if (new_size + 1 > s->capacity) {
        size_t new_capacity = (s->capacity == 0) ? new_size + 1 : s->capacity * 2;

        char* temp = (char*)realloc(s->data, new_capacity);
        if (temp == NULL) return NULL;

        s->data = temp;
        s->capacity = new_capacity;
    }

    memcpy(&s->data[pos], str, strlen(str));

    s->size = new_size;
    s->data[s->size] = '\0';

    return s;
}

void pushback(string* s, char val) {
    if (s == NULL || s->data == NULL) return;

    if (s->size + 2 > s->capacity) {
        size_t new_capacity = (s->capacity == 0) ? 16 : s->capacity * 2;
        
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

int empty(const string* s) {
    if (s == NULL || s->data == NULL || s->size == 0)
        return 1;

    return 0;
}
string* erase(string* s, size_t pos, size_t len) {
    if (s == NULL || s->data == NULL) return NULL;
    if (pos > s->size) return NULL;

    if (len > s->size - pos) len = s->size - pos;
    if (len == 0) return s;

    void* dest = s->data + pos;
    void* src = s->data + pos + len;
    size_t bytes_to_move = s->size - pos - len + 1;

    memmove(dest, src, bytes_to_move);

    s->size -= len;

    return s;
}

// ========== Elements accesess
const char* at(const string* s, size_t pos) {
    if (s == NULL || s->data == NULL || pos >= s->size) return NULL;

    return &s->data[pos];
}

const char* back(const string* s) {
    return &s->data[s->size - 1];
}
const char* begin(const string* s) {
    return s->data;
}
const char* end(const string* s) {
    return &s->data[s->size];
}

size_t copy(string* s, char* dest, size_t len, size_t pos) {
    if (s == NULL || s->data == NULL) return 0;

    for (size_t i = 0; i < len; i++) {
        dest[i] = s->data[pos++];
    }

    dest[len] = '\0';

    return len;
}
int compareall(const string* s1, const string* s2) {
    if (s1 == s2) return 0;

    if (s1 == NULL || s1->data == NULL) return -1;
    if (s2 == NULL || s2->data == NULL) return 1;

    size_t len1 = s1->size;
    size_t len2 = s2->size;
    size_t min_len = (len1 > len2) ? len2 : len1;

    int res = memcmp(s1->data, s2->data, min_len);

    if (res != 0) return (res < 0) ? -1 : 1;

    if (len1 < len2) return -1;
    if (len1 > len2) return 1;

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

size_t find(const string* s, const string* needle) {
    if (!s || !s->data) return -1;
    if (needle->size == 0 || !needle || !needle->data) return 0;
    if (s->size < needle->size) return -1;
    
    size_t table[256];
    size_t len = needle->size;

    for (int i = 0; i < 256; i++)
        table[i] = len;

    for (size_t i = 0; i < len - 1; i++)
        table[(unsigned char)needle->data[i]] = len - 1 - i;
        
    size_t shift = 0;
    while (shift <= s->size - len) {

        size_t i = len - 1;
        while (needle->data[i] == s->data[shift + i]){
            if (i == 0) return shift;
            i--;
        }

        unsigned char bad_char = (unsigned char)s->data[shift + len - 1];
        shift += table[bad_char];
    }

    return -1;
}
size_t rfind(const string* s, const string* needle) {
    if (!s || !s->data) return -1;
    if (needle->size == 0 || !needle || !needle->data) return 0;
    if (s->size < needle->size) return -1;

    size_t table[256];
    size_t len = needle->size;

    for (int i = 0; i < 256; i++)
        table[i] = len;

    for (size_t i = len - 1; i >= 1; i--)
        table[(unsigned char)needle->data[i]] = i;

    size_t shift = s->size - len;
    while (shift > 0) {
        size_t i = 0;
        while (needle->data[i] == s->data[shift + i]) {
            if (i == len) return shift;
            i++;
        }

        unsigned char bad_char = (unsigned char)s->data[shift];
        shift -= table[bad_char];
    }

    return -1;
}
string* substr(const string* s, size_t pos, size_t len) {
    if (!s || !s->data || pos > s->size) return NULL;
    if (len > s->size - pos)
        len = s->size - pos;

    char* temp = (char*)malloc(len + 1);
    if (!temp) return NULL;

    memcpy(temp, s->data + pos, len);
    temp[len] = '\0';

    string* res = strnew(temp);
    free(temp);

    return res;
}

string* replace(string* s, size_t pos, size_t len, const string* str) {
    if (!s || !s->data || !str || !str->data) return NULL;
    if (pos > s->size) return NULL;

    size_t new_size = s->size - len + str->size;
    if (new_size + 1 > s->capacity) {
        size_t new_capacity = (s->capacity == 0) ? 16 : s->capacity * 2;
        if (new_capacity < new_size + 1)
            new_capacity = new_size + 1;

        char* temp = (char*)realloc(s->data, new_capacity);
        if (!temp) return NULL;

        s->data = temp;
        s->capacity = new_capacity;
    }

    void* dest = s->data + pos + str->size;
    void* src = s->data + pos + len;
    size_t bytes_to_move = s->size - pos - len + 1;
    memmove(dest, src, bytes_to_move);

    memcpy(s->data + pos, str->data, str->size);

    return src;
}