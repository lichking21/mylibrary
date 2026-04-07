#include <stdio.h>
#include "astring.h"

int main() {

    string* str = strnew("I am a football ball");
    if (str == NULL)
        printf("(FATAL) >> failed to creat string\n");

    printf("string data: %s\n", str->data);
    printf("string size: %zu\n", str->size);
    printf("string capasity: %zu\n", str->capacity);

    strfree(str);

    return 0;
}