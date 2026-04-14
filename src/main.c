#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astring.h"

int main() {

    string* str = strnew("Yaaa futbolnyi futblonyi");
    if (str == NULL) printf("(FATAL) >> failed to creat string\n");

    string* key = strnew("futblonyi");
    string* s = strnew("myachik");
    size_t found = rfind(str, key);

    replace(str, found, key->size, s);

    printf("string data: %s\n", str->data);
    printf("string size: %zu\n", str->size);
    printf("string capasity: %zu\n\n", str->capacity);
    
    strfree(s);
    strfree(key);
    strfree(str);

    return 0;
}