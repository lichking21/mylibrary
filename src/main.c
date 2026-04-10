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

    string* str1 = strnew("green apple");
    string* str2 = strnew("apple");

    if (compare(str1, 6, 5, str2))
        printf("green apple is an apple\n\n");

    strfree(str);


    return 0;
}