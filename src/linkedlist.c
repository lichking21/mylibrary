#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

Node* newnode(void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}

void printlist(Node* head) {
    if (!head) return;

    Node* curr = head;
    while(curr) {
        printf("%s", (char*)curr->data);
        if (curr->next) printf(" ==> ");

        curr = curr->next;
    }

    printf("\n\n");
}

void binsert(Node** head, void* data) {
    if (!head || !data) return;

    Node* n = newnode(data);
    n->next = *head;
    *head = n;
}
void insertafter(Node* prev, void* data) {
    if (!prev || !data) return;

    Node* n = newnode(data);

    n->next = prev->next;
    prev->next = n;
}
void einsert(Node* head, void* data) {
    if (!head || !data) return;

    Node* n = newnode(data);
    Node* curr = head;

    while(curr) {
        curr = curr->next;

        if (curr->next == NULL) {
            curr->next = n;
            n->next = NULL;
            break;
        }
    }
}