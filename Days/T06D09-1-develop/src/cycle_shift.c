#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *c);
void rotate_data(int *a, int n, int c);
void output(int *a, int n);

int main() {
  int c, n, data[NMAX];
  int miss = input(data, &n, &c);
  if (miss == 1) {
    printf("n/a");
    return 1;
  }
  rotate_data(data, n, c);
  output(data, n);

  return 0;
}

int input(int *a, int *n, int *c) {
  char waste;
  int miss = 0;
  if (((scanf("%d%c", n, &waste) != 1) && (waste != '\n')) || (*n > NMAX) ||
      (*n <= 0)) {
    miss = 1;
  }

  for (int *p = a; p < a + *n; p++) {
    scanf("%d", p);
    waste = getchar();
    if (waste != ' ') {
      if (waste != '\n' && p - a + 1 == *n) {
        miss = 1;
      }
    }
  }

  if (((scanf("%d%c", c, &waste) != 1) && (waste != '\n'))) {
    miss = 1;
  }

  return miss;
}

void rotate_data(int *a, int n, int c) {
  if (c > 0) {
    for (int i = 0; i < c; i++) {
      int temp_data = a[0];
      for (int i = 0; i < n - 1; i++) {
        a[i] = a[i + 1];
      }
      a[n - 1] = temp_data;
    }
  } else {
    c = -c;
    for (int i = 0; i < c; i++) {
      int temp_data = a[n - 1];
      for (int i = n - 1; i > 0; i--) {
        a[i] = a[i - 1];
      }
      a[0] = temp_data;
    }
  }
}

void output(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", a[i]);
    if (i < n - 1) {
      printf(" ");
    }
  }
}
