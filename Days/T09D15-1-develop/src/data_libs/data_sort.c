#include "data_sort.h"

void sort(double *data, int n) {
    int i = 0;
    int j = 0;
    int q;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                q = data[j];
                data[j] = data[j + 1];
                data[j + 1] = q;
            }
        }
    }
}
