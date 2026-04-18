#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "astring.h"

typedef struct Node {
    void* data;
    struct Node* next;
}Node;

// ======== Memory control ========
Node* newnode(void*);
void keyremove(Node**, void*, void (void*), int (void*, void*));
void destroylist(Node **, void (void*));

// ======== Nodes control ========
void binsert(Node**, void*);
void insertafter(Node*, void*);
void lpushback(Node*, void*);
Node* lreverse(Node**);

// ======== Nodes access ========
Node* lfind(Node*, void*, int (void*, void*));
void* lat(Node*, size_t);
void* lpopfront(Node** head, void (void*));

// ======== Utilities ========
size_t llength(Node*);
void printlist(Node*);
int cmpstr(void*, void*);
int cmpint(void*, void*);

#endif