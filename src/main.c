#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astring.h"
#include "linkedlist.h"

int main() {
    
    string* s1 = strnew("FRIENDLY THUGG");
    string* s2 = strnew("52");
    string* s3 = strnew("NGG");

    Node* head = newnode(s1->data);
    head->next = newnode(s2->data);
    head->next->next = newnode(s3->data);

    printlist(head);

    return 0;
}