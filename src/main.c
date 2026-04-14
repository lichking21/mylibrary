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

    string* s1 = strnew("hui");
    string* s2 = strnew("chlen");
    printf("before swap: ");
    printf("s1 = %s, s2 = %s\n", s1->data, s2->data);
    swap(s1, s2);
    printf("after swap: ");
    printf("s1 = %s, s2 = %s\n", s1->data, s2->data);
    
    strfree(str);


    return 0;
}