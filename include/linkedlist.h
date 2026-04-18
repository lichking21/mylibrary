#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "astring.h"

typedef struct Node {
    void* data;
    struct Node* next;
}Node;

// ======== Help functions ========
int cmpstr(void*, void*);
int cmpint(void*, void*);

// ======== Memory control ========
Node* newnode(void*);
void keyremove(Node**, void*, void (void*), int (void*, void*));
void destroylist(Node **, void (void*));

// ======== Nodes control ========
void binsert(Node**, void*);
void insertafter(Node*, void*);
void lpushback(Node*, void*);

// ======== Nodes access ========
Node* lfind(Node*, void*, int (void*, void*));

// ======== Utilities ========
void printlist(Node*);

#endif