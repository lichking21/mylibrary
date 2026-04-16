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
    Node* n2 = newnode(s2->data);
    Node* n3 = newnode(s3->data);

    head->next = n2;
    n2->next = n3;

    insertafter(n2, "MVP");
    printlist(head);

    return 0;
}