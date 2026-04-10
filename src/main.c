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

    string* str1 = strnew("red apple");
    string* str2 = strnew("red apple");

    if (compareall(str1, str2) == 0)
        printf("both are equal\n\n");

    strfree(str);


    return 0;
}