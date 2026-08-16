#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avector.h"

int main() {

    size_t elem_size = sizeof(char*);
    size_t capacity = 8;

    vector* vec = vecnew(elem_size, capacity);

    char* c = "FRIENDLY";
    char* c2 = "THUGG";
    char* c3 = "52";

    vpush_back(vec, &c);
    vpush_back(vec, &c2);
    vpush_back(vec, &c3);

    char** ngg = (char**)vdata(vec);

    printf("Vec1 content: ");
    for (size_t i = 0; i < vec->size; i++) printf("%s ", ngg[i]);
    printf("\n");

    vector* vec2 = vecnew(sizeof(char*), 8);
    char* cc = "TUN";
    char* cc2 = "TUN";
    char* cc3 = "SAHUR";

    vpush_back(vec2, &cc);
    vpush_back(vec2, &cc2);
    vpush_back(vec2, &cc3);

    char** tts = (char**)vdata(vec2);

    printf("Vec2 content: ");
    for (size_t i = 0; i < vec2->size; i++) printf("%s ", tts[i]);
    printf("\n");

    // New functions use example
    vswap(vec, vec2);
    char** newvec = (char**)vdata(vec);

    printf("Vec1 content: ");
    for (size_t i = 0; i < vec->size; i++) printf("%s ", newvec[i]);
    printf("\n");

    char** newvec2 = (char**)vdata(vec2);
    printf("Vec2 content: ");
    for (size_t i = 0; i < vec2->size; i++) printf("%s ", newvec2[i]);
    printf("\n");

    printf("\n");
    return 0;
}
