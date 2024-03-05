#include <math.h>
#include <stdio.h>

double fun();

int main() {
    double res = fun();
    if (res < 0.000001 && res > -0.000001) {
        printf("OK!");
    }
    return 0;
}

double fun() { return (1.0 / 13) * (pow(((2 - 1.0) / (2 + 1.0)), 20)); }
