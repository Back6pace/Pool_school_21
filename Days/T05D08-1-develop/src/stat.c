#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("n/a");
        return 1;
    }
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}

int input(int *a, int *n) {
    char waste;
    if (((scanf("%d%c", n, &waste) != 1) && (waste != '\n')) || (*n > NMAX) || (*n < 1)) {
        return 1;
    }

    for (int *p = a; p < a + *n; p++) {
        scanf("%d", p);
        waste = getchar();
        if (waste != ' ') {
            if (waste == '\n' && p - a + 1 == *n) {
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
    printf("\n");
}

int max(int *a, int n) {
    int Max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > Max) {
            Max = a[i];
        }
    }
    return Max;
}

int min(int *a, int n) {
    int Min = max(a, n);
    for (int i = 0; i < n; i++) {
        if (a[i] < Min) {
            Min = a[i];
        }
    }
    return Min;
}

double mean(int *a, int n) {
    double sum = 0;
    double res_mean;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    res_mean = sum / n;
    return res_mean;
}

double variance(int *a, int n) {
    double sum_sqrt = 0;
    for (int i = 0; i < n; i++) {
        sum_sqrt += (a[i] - mean(a, n)) * (a[i] - mean(a, n));
    }
    double res_variance = sum_sqrt / n;
    return res_variance;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}

