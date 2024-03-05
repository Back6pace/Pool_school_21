#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min); // Инициализация функции

int main() {
    int x, y, z; // Заводим 3 переменных 
    char waste; // Заводим переменную для мусора 
    if (scanf("%d%d%d%c", &x, &y, &z, &waste) != 3 && waste != '\n') { // Проверка на ошибки
        printf("n/a");
        return 1;
    }

    int max, min;

    maxmin(x, y, z, &max, &min);

    printf("%d %d", max, min);

    return 0;
}

void maxmin(int prob1, int prob2, int prob3, int *max, int *min) {
    *max = *min = prob1; // max и min = x

    if (prob2 > *max) *max = prob2; // Если y > x, то max = y
    if (prob2 < *min) *min = prob2; // Если y < x, то min = y

    if (prob3 > *max) *max = prob3; // Если z > y, то max = z
    if (prob3 < *min) *min = prob3; // Если z < y, то min = z
}
 