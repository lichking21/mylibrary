#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "alinkedlist.h"

// ======== Memory control ========
Node* al_newnode(void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}
int al_keyremove(Node** head, void* key, void (*free_data)(void*), int (*cmp)(const void*, const void*)) {
    assert(head != NULL && key != NULL && cmp != NULL);
    if (head == NULL || *head == NULL || key == NULL || cmp == NULL) return -1;

    Node* curr = *head;
    Node* prev = NULL;

    if (curr && cmp(curr->data, key) == 0) {
        *head = curr->next;

        if (free_data) free_data(curr->data);

        free(curr);
        return 0;
    }

    while (curr && cmp(curr->data, key) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) return 0;

    prev->next = curr->next;
    free(curr);

    return 0;
}
int al_destroylist(Node** head, void (*free_data)(void*)) {
    assert(head != NULL);
    if (head == NULL || *head == NULL) return -1;

    Node* curr = *head;

    while (curr) {
        Node* next = curr->next;
        if (free_data) free_data(curr->data);

        free(curr);
        curr = next;
    }

    *head = NULL;

    return 0;
}

// ======== Nodes control ========
int al_binsert(Node** head, void* data) {
    assert(head != NULL && data != NULL);
    if (head == NULL || data == NULL) return -1;

    Node* n = al_newnode(data);
    if (!n) return -1;

    n->next = *head;
    *head = n;

    return 0;
}
int al_insertafter(Node* prev, void* data) {
    assert(prev != NULL && data != NULL);
    if (prev == NULL || data == NULL) return -1;

    Node* n = al_newnode(data);
    if (!n) return -1;

    n->next = prev->next;
    prev->next = n;

    return 0;
}
int al_push_back(Node** head, void* data) {
    assert(*head != NULL && data != NULL);

    Node* n = al_newnode(data);
    if (!n) return -1;

    if (*head == NULL) {
        *head = n;
        return -1;
    }

    Node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = n;

    return 0;
}
Node* al_reverse(Node** head) {
    assert(head != NULL);
    if (head == NULL || *head == NULL) return NULL;

    Node* curr = *head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    *head = prev;

    return *head;
}

// ======== Nodes access ========
Node* al_find(Node* head, void* key, int (*cmp)(const void*, const void*)) {
    assert(head != NULL && key != NULL && cmp != NULL);
    if (head == NULL || key == NULL || cmp == NULL) return NULL;

    Node* curr = head;
    while (curr && cmp(curr->data, key) != 0) {
        curr = curr->next;
    }

    return curr;
}
void* al_at(Node* head, size_t idx) {
    assert(head != NULL);
    if (head == NULL) return NULL;

    Node* curr_node = head;
    size_t curr_idx = 0;

    while (curr_node && curr_idx != idx) {
        curr_node = curr_node->next;
        curr_idx++;
    }

    if (!curr_node) return NULL;
    return curr_node->data;
}
void* al_pop_front(Node** head) {
    assert(head != NULL && *head != NULL);
    if (head == NULL || *head == NULL) return NULL;

    Node* temp = *head;
    void* data = temp->data;
    *head = (*head)->next;

    free(temp);

    return data;
}
void* al_pop_back(Node** head) {
    assert(head != NULL && *head != NULL);
    if (head == NULL || *head == NULL) return NULL;

    Node* curr = *head;
    Node* prev = NULL;

    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    void* data = curr->data;

    if (!prev) *head = NULL;
    else prev->next = NULL;

    free(curr);

    return data;
}

// ======== Utilities ========
size_t al_length(Node* head) {
    if (head == NULL) return 0;

    Node* curr = head;
    size_t size = 0;

    while(curr) {
        curr = curr->next;
        size++;
    }

    return size;
}
int al_printlist(Node* head) {
    if (head == NULL) {
        printf("Empty List\n");
        return -1;
    }

    Node* curr = head;
    while(curr) {
        printf("%s", (char*)curr->data);
        if (curr->next) printf(" ==> ");

        curr = curr->next;
    }

    printf("\n\n");

    return 0;
}
int al_cmpstr(const void* s1, const void* s2) {
    return strcmp((char*)s1, (char*)s2);
}
int al_cmpint(const void* v1, const void* v2) {
    int val1 = *(int*)v1;
    int val2 = *(int*)v2;

    if (val1 == val2) return 0;
    return (val1 < val2) ? -1 : 1;
}
