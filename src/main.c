#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    printlist(head);

    char* last = (char*)lpopback(&head);
    if (last) printf("last val: %s\n", last);
    else printf("couldn't get last node");

    printlist(head);

    char* last2 = (char*)lpopback(&head);
    if (last2) printf("last val: %s\n", last2);
    else printf("couldn't get last node");

    printlist(head);

    return 0;
}