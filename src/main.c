#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astring.h"

int main() {

    string* str = strnew("I am a football ball");
    if (str == NULL)
        printf("(FATAL) >> failed to creat string\n");

    printf("string data: %s\n", str->data);
    printf("string size: %zu\n", str->size);
    printf("string capasity: %zu\n\n", str->capacity);

    char* s1 = strdup("Ya");
    char* s2 = " pidoras";
    printf("cstrappend res: %s\n", cstrappend(s1, s2));

    string* s3 = strnew("Eto ");
    string* s4 = strnew("52");
    strappend(s3, s4);
    printf("strappend res: %s\n\n", s3->data);

    printf("pushback res: \n");
    pushback(str, '!');
    printf("string data: %s\n", str->data);
    printf("string size: %zu\n", str->size);
    printf("string capasity: %zu\n\n", str->capacity);

    printf("popback res: \n");
    popback(str);
    printf("string data: %s\n", str->data);
    printf("string size: %zu\n", str->size);
    printf("string capasity: %zu\n\n", str->capacity);

    strfree(str);
    strfree(s3);
    strfree(s4);

    return 0;
}