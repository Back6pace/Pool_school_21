#include <math.h>
#include <stdio.h>

double function(double x);

int main() {
    double a;
    if (scanf("%lf", &a) != 1) {
        printf("n/a\n");
        return 0;
    }

    int waste = getchar();
    if (waste != 10) {
        printf("n/a\n");
        return 0;
    }
    printf("%.1lf\n", function(a));
}

double function(double x) {
    double func = 7 * 0.001 * pow(x, 4) + ((22.8 * pow(x, 1 / 3) - 1 * 1000) * x + 3) / (x * x / 2) -
                  x * pow(10 + x, 2 / x) - 1.01;
    return round(func * 10) / 10;
}