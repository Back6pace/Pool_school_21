#include <stdio.h>

int main() {
    double x, y;
    if (scanf("%lf%lf", &x, &y) != 2) {
        printf("n/a\n");
        return 0;
    }

    int waste = getchar();
    if (waste != 10) {
        printf("n/a\n");
        return 0;
    }

    int round_coor = x * x + y * y;

    if (round_coor <= 25) {
        printf("GOTCHA\n");
    } else {
        printf("MISS\n");
    }
}