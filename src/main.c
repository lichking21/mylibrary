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
    char* c2 = "THUGG";
    char* c3 = "52";

    vpushback(vec, &c);
    vpushback(vec, &c2);
    vpushback(vec, &c3);
    char** ngg = (char**)vec->data;
    // for (size_t i = 0; i < vec->size; i++) 
    //     printf("elem[%ld]: %s ", i, ngg[i]);

    // vassign example
    vector* vec2 = vecnew(elem_size, capacity);
    if (vec2) printf("vector2 was created\n");
    else printf("(ERR) >> failed to create vector2");    

    vassign(vec2, vbegin(vec), vend(vec));
    char** mvp = (char**)vec2->data;
    for (size_t i = 0; i < vec2->size; i++) 
        printf("%s ", mvp[i]);
        
    printf("\n");
    return 0;
}