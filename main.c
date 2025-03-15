#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void test_list() {
    printf("Initializing list... Fingers crossed!\n");
    LinkedList *list = list_create();
    if (!list) {
        printf("Oh no! The list creation failed. Somebody call tech support!\n");
        return;
    }

    int *a = malloc(sizeof(int)); *a = 10;
    int *b = malloc(sizeof(int)); *b = 20;
    int *c = malloc(sizeof(int)); *c = 30;
    
    list_add(list, a);
    list_add(list, b);
    list_add(list, c);
    
    printf("List size: %zu (Bigger than my patience)\n", list_size(list));
    
    int *retrieved;
    if (list_get_at(list, 1, (void**)&retrieved) == 0) {
        printf("Element at index 1: %d (Surprise!)\n", *retrieved);
    }
    
    int *d = malloc(sizeof(int)); *d = 40;
    printf("Inserting 40 at index 1... Do I smell chaos?\n");
    list_insert_at(list, 1, d);
    
    printf("List size after insertion: %zu (It’s growing faster than my to-do list)\n", list_size(list));
    
    if (list_get_at(list, 1, (void**)&retrieved) == 0) {
        printf("New element at index 1: %d (Hope it’s still legal)\n", *retrieved);
    }
    
    void *removed_data;
    printf("Attempting to remove element at index 2... If I disappear, tell my family I loved them.\n");
    list_remove_at(list, 2, &removed_data);
    printf("Removed element: %d (Vanished into the void!)\n", *(int*)removed_data);
    free(removed_data);
    
    printf("Final list size: %zu (Stable for now)\n", list_size(list));
    
    printf("Destroying list... Say your goodbyes!\n");
    list_destroy(list, free);
}

int main() {
    test_list();
    printf("\nAll tests completed! If you see this, nothing exploded.\n");
    return 0;
}
