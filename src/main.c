#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avector.h"

int main() {

    size_t elem_size = sizeof(char*);
    size_t capacity = 8;

    vector* vec = vecnew(elem_size, capacity);
    if (vec) printf("vector was created\n");
    else printf("(ERR) >> failed to create vector");

    char* c = "FRIENDLY";
    char* c2 = "THUGG";
    char* c3 = "52";

    vpushback(vec, &c);
    vpushback(vec, &c2);
    vpushback(vec, &c3);

    // New functions use example

    char** data = (char**)vdata(vec);
    char** begin = (char**)vbegin(vec);

    for (size_t i = 0; i < vec->size; i++) {
        printf("Value at index %zu: %s\n", i, data[i]);
    }

    printf("vbegin: %s", *begin);

    printf("\n");
    return 0;
}
