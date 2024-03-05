#include <stdio.h>
#define NMAX 10

int input(int *a, int *n); // Инициализация функций
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX]; 
    if (input(data, &n)) { // Проверка на ошибки, возвращает либо 1 либо 0
        printf("n/a");
        return 1;
    }
    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n) {
    char waste;
    if (((scanf("%d%c", n, &waste) != 1) && (waste != '\n')) || (*n > NMAX) || (*n < 0)) { // Проверка на вещ. числа, на символы, на то что вводимое число меньше 10
        return 1;
    }

    for (int *p = a; p < a + *n; p++) {
        scanf("%d", p);
        waste = getchar();
        if (waste != ' ') { // Если введен пробел, то все окей идем дальше
            if (waste == '\n' && p - a + 1 == *n) { // Проверка на то что строка может закончиться только энтером и кол-во введенных чисел не превышает, n чисел в массиве
                return 0;
            } else {
                return 1;
            }
        }
    }
    return *n;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = a[i] * a[i];
    }
}
