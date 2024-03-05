#include <math.h>
#include <stdio.h>

double Verezi(double x);
double Lemnistica(double x);
double Hiperbola(double x);

int main() {
    double pi = M_PI;
    double cons = pi / 20.5;
    double i = -pi;
    while (i <= pi) {
        double ver = Verezi(i);
        double Lemn = Lemnistica(i);
        double Hiperb = Hiperbola(i);
        if (Lemnistica(i) == -99999) {
            printf("%.7lf | %.7lf | - | %.7lf\n", i, ver, Hiperb);
        } else {
            printf("%.7lf | %.7lf | %.7lf | %.7lf\n", i, ver, Lemn, Hiperb);
        }
        i += cons;
    }
    return 0;
}
double Verezi(double x) {
    double vera = pow(1, 3) / (pow(1, 2) + pow(x, 2));
    return vera;
}

double Lemnistica(double x) {
    if (x < 0 || x > 1.45) {
        return -99999;
    } else {
        double Lem = sqrt(sqrt(pow(1, 4) + (4 * pow(x, 2) * pow(1, 2))) - pow(x, 2) - pow(1, 2));
        return Lem;
    }
}

double Hiperbola(double x) {
    double Hip = 1 / pow(x, 2);
    return Hip;
}
