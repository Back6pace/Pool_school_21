#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *n);
void output(int *a, int n);
void buble_sort(int *a, int n);
int main() {
  int n = 0;
  int *data = NULL;
  int miss = input(&data, &n);
  if (miss == 1) {
    printf("n/a");
    free(data);
    return 1;
  }
  buble_sort(data, n);
  output(data, n);
  free(data);
  return 0;
}

int input(int **a, int *n) {
  char waste;
  int miss = 0;
  if ((scanf("%d%c", n, &waste) != 2 || (waste != '\n')) || (*n <= 0)) {
    miss = 1;
  }

  *a = (int *)malloc(*n * sizeof(int));

  for (int i = 0; i < *n; i++) {
    if (scanf("%d", (*a) + i) != 1) {
      miss = 1;
      free(*a);
      break;
    }

    if (i < *n - 1) {
      getchar();
    }
  }
  return miss;
}

void buble_sort(int *a, int n) {
  int q;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        q = a[j];
        a[j] = a[j + 1];
        a[j + 1] = q;
      }
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
