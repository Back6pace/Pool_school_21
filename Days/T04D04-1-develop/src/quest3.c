#include <math.h>
#include <stdio.h>

int Fibonachi(int num);

int main() {
    int x;
    if (scanf("%d", &x) != 1) {
        printf("n/a\n");
        return 0;
    }

    int waste = getchar();
    if (waste != 10) {
        printf("n/a\n");
        return 0;
    }

    if (x == 0) {
        printf("n/a");
        return 0;
    }

    int max = 0;
    for (int i = 1; i <= x; i++) {
        max = Fibonachi(i);
    }
    printf("%d", max);
    return 0;
}

int Fibonachi(int num) {         // рекурсивная функция фибоначи
    if (num == 1 || num == 2) {  // Первые два числа всегда равны 1
        return 1;
    }
    return Fibonachi(num - 1) + Fibonachi(num - 2);  // Сложение двух предудущих чисел
}
