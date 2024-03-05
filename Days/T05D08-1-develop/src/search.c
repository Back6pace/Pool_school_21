/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n);
double total_result(int *a, int n);
double variance(int *a, int n);
double mean(int *a, int n);

int main() {
  int n, data[NMAX];
  if (input(data, &n)) {
    printf("n/a");
    return 1;
  }
  output(data, n);
  total_result(data, n);
  variance(data, n);
  mean(data, n);
  return 0;
}

int input(int *a, int *n) {
  char waste;
  if (((scanf("%d%c", n, &waste) != 1) && (waste != '\n')) || (*n > NMAX) ||
      (*n < 1)) {
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

double total_result(int *a, int n) {
  int result = 0;
  double var = variance(a, n);
  double mean_res = mean(a, n);
  for (int *p = a; p - a < n; p++) {
    if ((*p % 2 == 0) && (*p >= mean_res) &&
        (*p <= mean_res + (3 * sqrt(var)) && (*p != 0))) {
      result = *p;
    }
  }
  return result;
}

void output(int *a, int n) {
  int res = total_result(a, n);
  printf("%d", res);
}
