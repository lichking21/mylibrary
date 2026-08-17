#ifndef ALINKEDLIST_H
#define ALINKEDLIST_H
#include <stdio.h>

typedef struct Node {
    void* data;
    struct Node* next;
}Node;

// ======== Memory control ========
Node* al_newnode(void*);
int al_keyremove(Node**, void*, void (*) (void*), int (*) (const void*, const void*));
int al_destroylist(Node **, void (*) (void*));

// ======== Nodes control ========
int al_binsert(Node**, void*);
int al_insertafter(Node*, void*);
int al_push_back(Node**, void*);
Node* al_reverse(Node**);

// ======== Nodes access ========
Node* al_find(Node*, void*, int (*)(const void*, const void*));
void* al_at(Node*, size_t);
void* al_pop_front(Node**);
void* al_pop_back(Node**);

// ======== Utilities ========
size_t al_length(Node*);
int al_printlist(Node*);
int al_cmpstr(const void*, const void*);
int al_cmpint(const void*, const void*);

#endif
