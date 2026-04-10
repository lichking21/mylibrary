#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astring.h"

int main() {

    string* str = strnew("I am a football ball");
    if (str == NULL) printf("(FATAL) >> failed to creat string\n");

    printf("string data: %s\n", str->data);
    printf("string size: %zu\n", str->size);
    printf("string capasity: %zu\n\n", str->capacity);

    string* test = strnew("Test string...");
    char* dest = (char*)malloc(25);
    copy(test, dest, 6, 5);
    printf("destination contains: %s\n\n", dest);

    strfree(str);

    return 0;
}