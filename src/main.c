#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astring.h"

int main() {

    string* str = strnew("Yaaa futbolnyi myachik");
    if (str == NULL) printf("(FATAL) >> failed to creat string\n");

    printf("string data: %s\n", str->data);
    printf("string size: %zu\n", str->size);
    printf("string capasity: %zu\n\n", str->capacity);

    string* s = strnew("Yaaa");

    printf("string data: %s\n", s->data);
    printf("string size: %zu\n", s->size);
    printf("string capasity: %zu\n\n", s->capacity);

    strfree(str);
    strfree(s);

    return 0;
}