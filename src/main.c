#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avector.h"

int main() {

    size_t elem_size = sizeof(char*);
    size_t capacity = 8;

    vector* vec = avec_new(elem_size, capacity);

    char* c = "FRIENDLY";
    char* c2 = "THUGG";
    char* c3 = "52";

    avec_push_back(vec, &c);
    avec_push_back(vec, &c2);
    avec_push_back(vec, &c3);

    char** ngg = (char**)avec_data(vec);

    printf("Vec1 content: ");
    for (size_t i = 0; i < vec->size; i++) printf("%s ", ngg[i]);
    printf("\n");

    vector* vec2 = avec_new(sizeof(char*), 8);
    char* cc = "TUN";
    char* cc2 = "TUN";
    char* cc3 = "SAHUR";

    avec_push_back(vec2, &cc);
    avec_push_back(vec2, &cc2);
    avec_push_back(vec2, &cc3);

    char** tts = (char**)avec_data(vec2);

    printf("Vec2 content: ");
    for (size_t i = 0; i < vec2->size; i++) printf("%s ", tts[i]);
    printf("\n");

    // New functions use example
    avec_swap(vec, vec2);
    char** newvec = (char**)avec_data(vec);

    printf("Vec1 content: ");
    for (size_t i = 0; i < vec->size; i++) printf("%s ", newvec[i]);
    printf("\n");

    char** newvec2 = (char**)avec_data(vec2);
    printf("Vec2 content: ");
    for (size_t i = 0; i < vec2->size; i++) printf("%s ", newvec2[i]);
    printf("\n");

    printf("\n");
    return 0;
}
