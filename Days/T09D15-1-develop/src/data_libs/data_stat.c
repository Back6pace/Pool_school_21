#include "data_stat.h"

#include <math.h>
#include <stdio.h>

double max(double *data, int n) {
    double MAX = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] > MAX) {
            MAX = data[i];
        }
    }
    return MAX;
}

double min(double *data, int n) {
    double MIN = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < MIN) {
            MIN = data[i];
        }
    }
    return MIN;
}
double mean(double *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}
double variance(double *data, int n) {
    double sum = 0;
    double m = mean(data, n);
    for (int i = 0; i < n; i++) {
        sum += pow(data[i] - m, 2);
    }
    return sum / n;
}