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

    char* c = "FRIENDLY";

    vpushback(vec, c);
    printf("vec elem: %s\n", (char*)vec->data);

    return 0;
}