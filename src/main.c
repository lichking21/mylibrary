#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

int main() {
    
    size_t elem_size = sizeof(char*);
    size_t capacity = 8;

    vector* vec = vecnew(elem_size, capacity);
    if (vec) printf("vector was created\n");
    else printf("(ERR) >> failed to create vector");

    char* c = "FRIENDLY ";
    char* c2 = "THUGG ";
    char* c3 = "52 ";

    vpushback(vec, &c);
    vpushback(vec, &c2);
    vpushback(vec, &c3);
    char** ngg = (char**)vec->data;

    printf("size of vector: %ld\n", veclen(vec));

    for (size_t i = 0; i < vec->size; i++) printf("elem[%ld]: %s\n", i, ngg[i]);

    return 0;
}