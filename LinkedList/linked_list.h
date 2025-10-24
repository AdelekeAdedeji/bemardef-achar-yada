/* linked_list.h */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#define LIST_IS_EMPTY 1
#define LIST_IS_NOT_EMPTY 0
#define INSERT 1
#define DELETE 2
#define FREE 3
#define CALL 4


typedef enum {TYPE_INT=1, TYPE_FLOAT=2, TYPE_CHAR=3, TYPE_STRING=4 } type_t;


typedef union types_allowed {
    int int_value;
    char char_value;
    float float_value;
    const char* string_value;
} dyn_t;


typedef struct node {
    type_t type;

    dyn_t value;

    struct node* next_node;

} Node;


typedef struct list {
    Node* head;

    int length;

} Linked_List;


static int _track_length(Linked_List* list, type_t operation);

static int _linked_list_is_empty(Linked_List* list);

void linked_list_init(Linked_List* list, type_t data_type, dyn_t head_value);

void insert_new_node_begin(Linked_List* list, type_t data_type, dyn_t value);

void insert_new_node_at(Linked_List* list, type_t data_type, int index, dyn_t value);

void set_node_value(Node* node, type_t data_type, dyn_t value) ;

void insert_new_node_end(Linked_List* list, type_t data_type, dyn_t value);

void delete_node_begin(Linked_List* list);

void delete_node_at(Linked_List* list, int index);

void delete_node_end(Linked_List* list);

void print_linked_list(Linked_List* list);

static void _check_for_mem_alloc_error(Linked_List* list, Node* node);

static void _validate_index(Linked_List* list, Node* node, int index, char* operation);

void free_linked_list(Linked_List* list);

static void _check_for_empty_linked_list(Linked_List* list, char* print_text);

#endif