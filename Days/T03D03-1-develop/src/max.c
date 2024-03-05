#include <stdio.h>
int max(int a, int b);

int main() {
    int x, y;
    if (scanf("%d%d", &x, &y) != 2) {
        printf("n/a\n");
        return 1;
    }
    int waste = getchar();
    if (waste != 10) {
        printf("n/a\n");
        return 0;
    }

    printf("%d\n", max(x, y));
    return 0;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
    return 0;
}
