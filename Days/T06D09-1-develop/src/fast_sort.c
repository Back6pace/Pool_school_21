#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void merge_sort(int *a);
void merge_sort_recursion(int *a, int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);
void quick_sort(int *a, int left, int right);

int main() {
  int data[NMAX], res;
  res = input(data);
  int data2[NMAX];
  for (int i = 0; i < NMAX; i++) {
    data2[i] = data[i];
  }
  if (res) {
    quick_sort(data, 0, NMAX - 1);
    output(data);
    merge_sort(data2);
    output(data2);
  } else {
    printf("n/a");
  }
  return 0;
}

int input(int *a) {
  char waste;
  for (int *p = a; p < NMAX + a; p++) {
    scanf("%d", p);
    waste = getchar();
    if (waste != ' ') {
      if (waste == '\n' && p - a + 1 == NMAX) {
        return 1;
      } else {
        return 0;
      }
    }
  }
  return 0;
}

void merge_sort(int *a) { merge_sort_recursion(a, 0, NMAX - 1); }

void merge_sort_recursion(int *a, int l, int r) {

  if (l < r) {
    int m = l + (r - l) / 2;

    merge_sort_recursion(a, l, m);
    merge_sort_recursion(a, m + 1, r);

    merge_sorted_arrays(a, l, m, r);
  }
}

void merge_sorted_arrays(int a[], int l, int m, int r) {
  int left_length = m - l + 1;
  int right_length = r - m;

  int temp_left[left_length];
  int temp_right[right_length];

  int i, j, k;

  for (int i = 0; i < left_length; i++)
    temp_left[i] = a[l + i];

  for (int i = 0; i < right_length; i++)
    temp_right[i] = a[m + 1 + i];

  for (i = 0, j = 0, k = l; k <= r; k++) {
    if ((i < left_length) &&
        (j >= right_length || temp_left[i] <= temp_right[j])) {
      a[k] = temp_left[i];
      i++;
    } else {
      a[k] = temp_right[j];
      j++;
    }
  }
}

void quick_sort(int *a, int left, int right) {
  if (left > right)
    return;
  int p = a[(left + right) / 2];
  int i = left;
  int j = right;
  while (i <= j) {
    while (a[i] < p)
      i++;
    while (a[j] > p)
      j--;
    if (i <= j) {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      i++;
      j--;
    }
  }
  quick_sort(a, left, j);
  quick_sort(a, i, right);
}

void output(int *a) {
  for (int i = 0; i < NMAX; i++) {
    printf("%d", a[i]);
    if (i < NMAX - 1) {
      printf(" ");
    }
  }
  printf("\n");
}
