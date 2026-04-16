#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    void* data;
    struct Node* next;
}Node;

Node* newnode(void*);
void printlist(Node*);

void binsert(Node**, void*);
void insertafter(Node*, void*);
void einsert(Node*, void*);

#endif