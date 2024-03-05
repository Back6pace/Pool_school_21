#include <stdio.h>
int sum(int a, int b);
int minus(int a, int b);
int mult(int a, int b);
int divide(int a, int b);

int main() {
    int x, y;
    if (scanf("%d%d", &x, &y) != 2) {
        printf("n/a\n");
        return 0;
    }

    int waste = getchar();
    if (waste != 10) {
        printf("n/a\n");
        return 0;
    }

    if (y == 0) {
        printf("%d %d %d n/a\n", sum(x, y), minus(x, y), mult(x, y));
        return 0;
    }
    printf("%d %d %d %d\n", sum(x, y), minus(x, y), mult(x, y), divide(x, y));
    return 0;
}

int sum(int a, int b) { return a + b; }
int minus(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }
