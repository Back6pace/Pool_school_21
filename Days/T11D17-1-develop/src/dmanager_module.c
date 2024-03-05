#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    buble_sort(doors);
    output(doors);

    return 0;
}

void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void buble_sort(struct door* doors) {
    int q;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
        for (int j = 0; j < DOORS_COUNT - i - 1; j++) {
            if (doors[j].id > doors[j + 1].id) {
                q = doors[j].id;
                doors[j].id = doors[j + 1].id;
                doors[j + 1].id = q;
            }
        }
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d", doors[i].id, doors[i].status);
        if (i != DOORS_COUNT - 1) printf("\n");
    }
}
