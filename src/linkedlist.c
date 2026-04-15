#include <stdio.h>
#include "linkedlist.h"

Node* newnode(void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}

void binsert(Node* head, void* data) {
    Node* n = newnode(data);
    n->next = head;
}