/* linked_list.c
* This file contains the implementation of the linked list and it's operations
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


void linked_list_init(Linked_List* list, type_t data_type, dyn_t head_value) {
    list->head = malloc(sizeof(Node));

    _check_for_mem_alloc_error(list, list->head);

    set_node_value(list->head, data_type, head_value);

    list->length = 0;

    list->head->type = data_type;

    list->head->next_node = NULL;

    _track_length(list, INSERT);
}

void insert_new_node_begin(Linked_List* list, type_t data_type, dyn_t value) {
    Node* new_node = (Node *) malloc(sizeof(Node));

    _check_for_mem_alloc_error(list, new_node);

    new_node->next_node = list->head;

    list->head = new_node;

    set_node_value(list->head, data_type, value);

    (list->head)->type = data_type;

    _track_length(list, INSERT);
}

void insert_new_node_at(Linked_List* list, type_t data_type, int index, dyn_t value) {
    int counter = 0;

    Node* current_node = list->head;

    Node* tracker = current_node;

    while (counter != index && current_node != NULL) {
        tracker = current_node;
        current_node = current_node->next_node;
        counter++;
    }

    _validate_index(list, current_node, index, "insert");

    Node* new_node = (Node *) malloc(sizeof(Node));

    _check_for_mem_alloc_error(list, new_node);

    set_node_value(new_node, data_type, value);

    new_node->type = data_type;

    tracker->next_node = new_node;

    new_node->next_node = current_node;

    _track_length(list, INSERT);
}


void insert_new_node_end(Linked_List* list, type_t data_type, dyn_t value) {
    Node* current_node = list->head;

    while (current_node->next_node != NULL) {
        current_node = current_node->next_node;
    }

    current_node->next_node = malloc(sizeof(Node));

    _check_for_mem_alloc_error(list, current_node->next_node);

    set_node_value(current_node->next_node, data_type, value);

    current_node->next_node->type = data_type;

    current_node->next_node->next_node = NULL;

    _track_length(list, INSERT);
}

void delete_node_begin(Linked_List* list) {
    _check_for_empty_linked_list(list, "delete");

    Node* deleted_node = list->head;

    list->head = list->head->next_node;

    free(deleted_node);

    _track_length(list, DELETE);
}

void delete_node_at(Linked_List* list, int index) {
    int counter = 0;

    Node* current_node = list->head;

    Node* tracker = current_node;

    while (counter != index && current_node != NULL) {
        tracker = current_node;
        current_node = current_node->next_node;
        counter++;
    }

    _validate_index(list, current_node, index, "delete");

    tracker->next_node = current_node->next_node;

    free(current_node);

    _track_length(list, DELETE);
}

void delete_node_end(Linked_List* list) {
    _check_for_empty_linked_list(list, "delete");

    Node* node = list->head;

    Node* tracker = node;

    while (node->next_node) {
        tracker = node;
        node = node->next_node;
    }

    tracker->next_node = node->next_node;

    free(node);

    _track_length(list, DELETE);
}

void set_node_value(Node* node , type_t data_type, dyn_t value) {
    switch (data_type) {
        case TYPE_INT:
            node->value.int_value = value.int_value;
            break;
        case TYPE_FLOAT:
            node->value.float_value = value.float_value;
            break;
        case TYPE_STRING:
            node->value.string_value = value.string_value;
            break;
        case TYPE_CHAR:
            node->value.char_value = value.char_value;
            break;
    }
}

void print_linked_list(Linked_List* list) {
    _check_for_empty_linked_list(list, "print");

    Node* tracker = list->head;

    printf("LinkedList( ");

    while (tracker) {
        switch (tracker->type) {
            case TYPE_INT:
                printf("%d -----> ", tracker->value.int_value);
                break;
            case TYPE_STRING:
                printf("%s -----> ", tracker->value.string_value);
                break;
            case TYPE_FLOAT:
                printf("%f -----> ", tracker->value.float_value);
                break;
            case TYPE_CHAR:
                printf("%c -----> ", tracker->value.char_value);
                break;
        }

        tracker = tracker->next_node;
    }

    printf("NULL )\n");
}


void free_linked_list(Linked_List* list) {
    Node* current_node = list -> head;

    Node* previous_node = current_node;

    while (current_node) {
        current_node = current_node->next_node;
        free(previous_node);
        previous_node = current_node;
    }

    _track_length(list, FREE);

    free(list);
}

static void _check_for_mem_alloc_error(Linked_List* list, Node* node) {
    if (node == NULL) {
        printf("Memory allocation error: Memory allocation failed!!!\n");
        if (list != NULL) {
            free_linked_list(list);
        }
        exit(EXIT_FAILURE);
    }
}

static void _validate_index(Linked_List* list, Node* node, int index, char* operation) {
    if (!index) {
        printf("Error: Beginning of linked list, use %s_node_begin() instead\n", operation);
        free_linked_list(list);
        exit(EXIT_FAILURE);

    }

    if (node == NULL) {
        printf("Error: Index %d out of bounds. List has fewer nodes than specified.\n", index);
        free_linked_list(list);
        exit(EXIT_FAILURE);
    }
}

static int _track_length(Linked_List* list, type_t operation) {
    if (operation == FREE) {
         list->length= 0;
        return list->length;
    }

    return operation == INSERT ? ++list->length : --list->length;
}

static int _linked_list_is_empty(Linked_List* list) {
    return list->length == 0 ? LIST_IS_EMPTY : LIST_IS_NOT_EMPTY;
}

static void _check_for_empty_linked_list(Linked_List* list, char* print_text) {
    if ( _linked_list_is_empty(list) ) {
        printf("Error: Cannot perform %s on an empty list.\n", print_text);
        free(list);
        exit(EXIT_FAILURE);
    }
}

