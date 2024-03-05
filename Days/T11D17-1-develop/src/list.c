#include "list.h"

/*
инициализация структуры односвязного списка на базе  door переданной structr
*/
struct node* init(struct door* door) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    if (new_node != NULL) {
        new_node->data.id = door->id;
        new_node->data.status = door->status;
        new_node->next = NULL;
    }
    return new_node;
};

/*
вставка нового элемента struct door в односвязный список после переданного узла elem
*/
struct node* add_door(struct node* elem, struct door* door) {
    struct node* new_node = NULL;

    if (elem != NULL) {
        struct node* node1 = (struct node*)malloc(sizeof(struct node));
        if (node1 != NULL) {
            node1->data.id = door->id;
            node1->data.status = door->status;
            node1->next = elem->next;
            elem->next = node1;
        }
    }
    return new_node;
}

/*
поиск двери в списке по её id
*/
struct node* find_door(int door_id, struct node* root) {
    struct node* ptr_node = root;
    while (ptr_node != NULL) {
        if (ptr_node->data.id == door_id) {
            break;
        }
        ptr_node = ptr_node->next;
    }
    return ptr_node;
}

/*
удаление элемента списка
*/
struct node* remove_door(struct node* elem, struct node* root) {
    struct node* ptr_node = root;

    if (elem == root) {
        ptr_node = root->next;
        free(elem);
    } else {
        while (ptr_node->next != elem) {
            ptr_node = ptr_node->next;
        }
        ptr_node->next = elem->next;
        free(elem);
        ptr_node = root;
    }
    return ptr_node;
}

/*
освобождение памяти, занимаемой структурой списка
*/
void destroy(struct node* root) {
    struct node* ptr_node = root;

    while (ptr_node != NULL) {
        struct node* del_elem = ptr_node;
        ptr_node = ptr_node->next;
        free(del_elem);
    }
}