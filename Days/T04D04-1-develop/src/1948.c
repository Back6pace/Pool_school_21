#include <math.h>
#include <stdio.h>

int is_simple_num(int number);  // инициализируем функции
int ostatok(int a, int b);
int abs(int number);

int main() {
    int num;
    if (scanf("%d", &num) != 1) {
        printf("n/a\n");
        return 0;
    }

    int waste = getchar();
    if (waste != 10) {
        printf("n/a\n");
        return 0;
    }

    int max = 1;

    for (int i = 2; i <= abs(num); i++) {  // проходимся циком от 2 до нашего числа
        if (ostatok(num, i) == 0 && is_simple_num(i)) {
            max = i;
        }
    }

    printf("%d\n", max);

    return 0;
}

int abs(int number) {  // Модуль числа
    if (number < 0) {
        return -number;
    } else {
        return number;
    }
    return 0;
}

int is_simple_num(int number) {  // Проверка числа на простоту
    for (int i = 2; i < abs(number); i++) {
        if (ostatok(number, i) == 0) {
            return 0;
        }
    }
    return 1;
}

int ostatok(int a, int b) {  // Нахождение остаток от числа
    if (a == 0) {
        return 0;
    }

    int count = 0;
    int remainder = 0;
    if (a >= b) {
        while (a >= b) {
            a -= b;
            count++;
        }
        remainder = a;
    } else {
        while (a <= b) {
            a += b;
            count++;
        }
        remainder = a;
    }
    return remainder;
}
