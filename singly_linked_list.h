#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stddef.h>

// Linked list structure
typedef struct LinkedList LinkedList;

// Linked list functions
LinkedList *list_create(void);
int list_add(LinkedList *list, void *data);
int list_insert_at(LinkedList *list, size_t index, void *data);
int list_get_at(LinkedList *list, size_t index, void **out_data);
int list_remove_at(LinkedList *list, size_t index, void **out_data);
size_t list_size(const LinkedList *list);
void list_destroy(LinkedList *list, void (*free_func)(void *));

// Linked list iterator structure
typedef struct ListIterator ListIterator;

// Linked list iterator functions
ListIterator *list_iterator_create(LinkedList *list);
int list_iterator_next(ListIterator *iter, void **out_data);
void list_iterator_reset(ListIterator *iter);
void list_iterator_destroy(ListIterator *iter);

#endif // SINGLY_LINKED_LIST_H
