#include "singly_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

// Node structure
typedef struct Node {
    void *data;
    struct Node *next;
} Node;

// Linked list structure
struct LinkedList {
    Node *head;
    size_t size;
};

// Creates and initializes an empty linked list
LinkedList *list_create(void) {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (!list) return NULL;
    list->head = NULL;
    list->size = 0;
    return list;
}

// Inserts a new node at the end of the list
int list_add(LinkedList *list, void *data) {
    if (!list) return -1;
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) return -1;
    new_node->data = data;
    new_node->next = NULL;
    
    if (!list->head) {
        list->head = new_node;
    } else {
        Node *temp = list->head;
        while (temp->next) temp = temp->next;
        temp->next = new_node;
    }
    list->size++;
    return 0;
}

// Inserts a node at a specific index
int list_insert_at(LinkedList *list, size_t index, void *data) {
    if (!list || index > list->size) return -1;
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) return -1;
    new_node->data = data;
    
    if (index == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        Node *temp = list->head;
        for (size_t i = 0; i < index - 1; i++) temp = temp->next;
        new_node->next = temp->next;
        temp->next = new_node;
    }
    list->size++;
    return 0;
}

// Fetches an element at a specific index
int list_get_at(LinkedList *list, size_t index, void **out_data) {
    if (!list || index >= list->size || !out_data) return -1;
    Node *temp = list->head;
    for (size_t i = 0; i < index; i++) temp = temp->next;
    *out_data = temp->data;
    return 0;
}

// Removes and returns the element at a specific index
int list_remove_at(LinkedList *list, size_t index, void **out_data) {
    if (!list || index >= list->size || !out_data) return -1;
    Node *temp = list->head, *prev = NULL;
    
    if (index == 0) {
        list->head = temp->next;
    } else {
        for (size_t i = 0; i < index; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
    }
    *out_data = temp->data;
    free(temp);
    list->size--;
    return 0;
}

// Returns the size of the list
size_t list_size(const LinkedList *list) {
    return list ? list->size : 0;
}

// Frees all nodes and applies a free function if provided
void list_destroy(LinkedList *list, void (*free_func)(void *)) {
    if (!list) return;
    Node *temp = list->head;
    while (temp) {
        Node *next = temp->next;
        if (free_func) free_func(temp->data);
        free(temp);
        temp = next;
    }
    free(list);
}
