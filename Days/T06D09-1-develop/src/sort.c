#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void buble_sort(int *a);
int main() {
  int data[NMAX];
  int miss = input(data);
  if (miss == 1) {
    buble_sort(data);
    output(data);
  } else {
    printf("n/a");
  }
  return 0;
}

int input(int *a) {
  char waste;
  int miss = 0;
  for (int *p = a; p < NMAX + a; p++) {
    scanf("%d", p);
    waste = getchar();
    if (waste != ' ') {
      if (waste == '\n' && p - a + 1 == NMAX) {
        miss = 1;
      } else {
        miss = 0;
      }
    }
  }
  return miss;
}

void buble_sort(int *a) {
  int i = 0;
  int j = 0;
  int q;
  for (i = 0; i < NMAX - 1; i++) {
    for (j = 0; j < NMAX - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        q = a[j];
        a[j] = a[j + 1];
        a[j + 1] = q;
      }
    }
  }
}

void output(int *a) {
  for (int i = 0; i < NMAX; i++) {
    printf("%d", a[i]);
    if (i < NMAX - 1) {
      printf(" ");
    }
  }
}
