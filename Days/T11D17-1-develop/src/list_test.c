#include "list.h"

#include <stdio.h>

void print_door_list(struct node *root);
int len_of_list(struct node *root);

int main() {
    struct door door1 = {0, 1};
    struct node *root = init(&door1);
    printf("Дверь для иициализации: ");
    printf("%d, %d\n", door1.id, door1.status);

    printf("Выход: ");
    if (root != NULL) {
        printf("SUCCES\n");
    } else {
        printf("FAIL");
    }

    struct door door2 = {1, 1};
    struct node *add_elem = add_door(root, &door2);
    printf("Вход: ");
    print_door_list(root);

    printf("Выход: ");
    if (add_elem != NULL) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    find_door(&door1, root);

    printf("Удаление двери\n");
    int len_start = len_of_list(root);

    struct node *ptr_node = root;
    root = remove_door(ptr_node, root);
    int len_finish = len_of_list(root);

    printf("Выход: ");
    if (len_start - 1 == len_finish) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    destroy(root);
    printf("SUCCES");

    return 0;
}

void print_door_list(struct node *root) {
    struct node *ptr_node = root;
    while (1) {
        if (ptr_node == NULL) {
            break;
        }
        printf("%d, %d; ", ptr_node->data.id, ptr_node->data.status);

        ptr_node = ptr_node->next;
    }
}

int len_of_list(struct node *root) {
    int cnt = 0;
    struct node *ptr_node = root;
    while (ptr_node != NULL) {
        cnt++;
        ptr_node = ptr_node->next;
    }
    return cnt;
}
