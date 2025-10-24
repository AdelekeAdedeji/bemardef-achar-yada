#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"



int main(void){
    Linked_List* list1 = malloc(sizeof(Linked_List));

    Linked_List* list2 = malloc(sizeof(Linked_List));

    linked_list_init(list1, TYPE_INT, (dyn_t) {.int_value = 15});
    linked_list_init(list2, TYPE_STRING, (dyn_t) {.string_value = "This is yet another list"});

    insert_new_node_end(list1, TYPE_STRING, (dyn_t) {.string_value = "ST 24 WAY ILLINOIS STREET "});
    insert_new_node_end(list1, TYPE_FLOAT, (dyn_t) {.float_value = 25.77f});
    insert_new_node_end(list1, TYPE_CHAR, (dyn_t) {.char_value = 'A'});
    insert_new_node_end(list1, TYPE_STRING, (dyn_t) {.string_value = "Linux is Best!!!"});
    insert_new_node_end(list1, TYPE_STRING, (dyn_t) {.string_value = "C Programs are interesting."});
    insert_new_node_end(list1, TYPE_FLOAT, (dyn_t) {.float_value = 35.0f});

    insert_new_node_end(list2, TYPE_INT, (dyn_t) {.int_value = 5});
    insert_new_node_end(list2, TYPE_INT, (dyn_t) {.int_value = 2});
    insert_new_node_end(list2, TYPE_STRING, (dyn_t) {.string_value = "C"});
    insert_new_node_end(list2, TYPE_STRING, (dyn_t) {.string_value = "BeOS"});
    insert_new_node_end(list2, TYPE_FLOAT, (dyn_t) {.float_value = 15.0f});

    insert_new_node_begin(list1, TYPE_FLOAT, (dyn_t) {.float_value = 135.0f});
    insert_new_node_begin(list1, TYPE_STRING, (dyn_t) {.string_value = "This is string"});

    insert_new_node_begin(list2, TYPE_FLOAT, (dyn_t) {.float_value = 75.0f});
    insert_new_node_begin(list2, TYPE_STRING, (dyn_t) {.string_value = "Origin's Edge"});

    insert_new_node_at(list1, TYPE_FLOAT, 3, (dyn_t) {.float_value = 4.67f});
    insert_new_node_at(list1, TYPE_INT, 4, (dyn_t) {.int_value = 10});

    insert_new_node_at(list2, TYPE_FLOAT, 1, (dyn_t) {.float_value = 2.35f});
    insert_new_node_at(list2, TYPE_STRING, 2, (dyn_t) {.string_value = "The Rational Meadow"});


    delete_node_begin(list1);
    delete_node_begin(list1);

    delete_node_begin(list2);
    delete_node_begin(list2);

    delete_node_end(list1);
    delete_node_end(list1);

    delete_node_end(list2);
    delete_node_end(list2);

    delete_node_at(list1, 3);
    delete_node_at(list1, 2);

    delete_node_at(list2, 1);
    delete_node_at(list2, 3);

    print_linked_list(list1);
    printf("Length of linked list = %d\n", list1->length);

    print_linked_list(list2);
    printf("Length of linked list = %d\n", list2->length);

    free_linked_list(list1);

    free_linked_list(list2);

    return 0;
}

