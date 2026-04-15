#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct {
    void* data;
    Node* next;
}Node;

Node* newnode(void* data);

#endif