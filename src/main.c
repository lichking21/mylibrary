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

    vpush_back(vec, &c);
    vpush_back(vec, &c2);
    vpush_back(vec, &c3);

    char** ngg = (char**)vdata(vec);

    for (size_t i = 0; i < vec->size; i++) printf("%s ", ngg[i]);
    printf("\n");

    // New functions use example
    printf("Max capacity: %ld\n", vmax_size(vec));

    size_t n = 10;
    vreserve(vec, n);
    printf("New max capacity: %ld", vmax_size(vec));

    printf("\n");
    return 0;
}
