#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void test_list() {
    LinkedList *list = list_create();
    if (!list) {
        printf("Failed to create list\n");
        return;
    }

    int a = 10, b = 20, c = 30;
    list_add(list, &a);
    list_add(list, &b);
    list_add(list, &c);

    printf("List size: %zu\n", list_size(list));

    int *retrieved;
    if (list_get_at(list, 1, (void**)&retrieved) == 0) {
        printf("Element at index 1: %d\n", *retrieved);
    }

    int d = 40;
    list_insert_at(list, 1, &d);

    printf("List size after insertion: %zu\n", list_size(list));

    if (list_get_at(list, 1, (void**)&retrieved) == 0) {
        printf("New element at index 1: %d\n", *retrieved);
    }

    void *removed_data;
    list_remove_at(list, 2, &removed_data);
    printf("Removed element: %d\n", *(int*)removed_data); 

    printf("Final list size: %zu\n", list_size(list)); 

    list_destroy(list, NULL);
}

int main() {
    test_list();
    return 0;
}
