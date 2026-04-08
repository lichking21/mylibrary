#include <stdio.h>
#include "astring.h"

int main() {

    string* str = strnew("I am a football ball");
    if (str == NULL)
        printf("(FATAL) >> failed to creat string\n");

    printf("string data: %s\n", str->data);
    printf("string size: %zu\n", str->size);
    printf("string capasity: %zu\n", str->capacity);

    string* s3 = strnew("Eto ");
    string* s4 = strnew("52");
    printf("strappend res: %s\n", strappend(s3, s4)->data);

    strfree(str);
    strfree(s3);
    strfree(s4);

    return 0;
}