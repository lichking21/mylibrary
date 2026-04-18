#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

// ======== Help functions ========
int cmpstr(void* s1, void* s2) {
    return strcmp((char*)s1, (char*)s2);
}
int cmpint(void* v1, void* v2) {
    int val1 = *(int*)v1;
    int val2 = *(int*)v2;

    if (val1 == val2) return 0;
    return (val1 < val2) ? -1 : 1;
}

// ======== Memory control ========
Node* newnode(void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}
void keyremove(Node** head, void* key, void (*free_data)(void*), int (*cmp)(void*, void*)) {
    if (!head || !*head || !key) return;

    Node* curr = *head;
    Node* prev = NULL;

    if (curr && cmp(curr->data, key) == 0) {
        *head = curr->next;

        if (free_data) free_data(curr->data);

        free(curr);
        return;
    }

    while (curr && cmp(curr->data, key) != 0) {        
        prev = curr;
        curr = curr->next;
    }

    if (!curr) return;

    prev->next = curr->next;
    free(curr);
}
void destroylist(Node** head, void (*free_data)(void*)) {
    if (!head || !*head) return;

    Node* curr = *head;

    while (curr) {
        Node* next = curr->next;
        if (free_data) free_data(curr->data);

        free(curr->data);
        curr = next;
    }
}

// ======== Nodes control ========
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
void lpushback(Node* head, void* data) {
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

// ======== Nodes access ========
Node* lfind(Node* head, void* key, int (*cmp)(void*, void*)) {
    if (!head || !key || !cmp) return NULL;

    Node* curr = head;
    while (curr && cmp(curr->data, key) != 0) {
        curr = curr->next;
    }

    return curr;
}

// ======== Utilities ========
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
