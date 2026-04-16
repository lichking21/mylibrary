#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "astring.h"

typedef struct Node {
    void* data;
    struct Node* next;
}Node;

// To compare data types 
int cmpstr(void*, void*);
int cmpint(void*, void*);

Node* newnode(void*);
void printlist(Node*);

void binsert(Node**, void*);
void insertafter(Node*, void*);
void einsert(Node*, void*);

void keyremove(Node**, void*, void (void*), int (void*, void*));

#endif