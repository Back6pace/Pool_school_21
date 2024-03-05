#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);
void output(int *buffer, int length);

int main() {
  int length, data[NMAX], data2[NMAX];

  if (input(data, &length)) {
    printf("n/a");
    return 1;
  }

  int sum = sum_numbers(data, length);
  if (sum == -1) {
    printf("n/a");
    return 1;
  }
  int res = find_numbers(data, length, sum, data2);
  output(data2, res);

  return 0;
}

int input(int *buffer, int *length) {
  char waste;
  if (((scanf("%d%c", length, &waste) != 1) && (waste != '\n')) ||
      (*length > NMAX) || (*length < 1)) {
    return 1;
  }
  for (int *p = buffer; p - buffer < *length; p++) {
    scanf("%d", p);
    waste = getchar();
    if (waste != ' ') {
      if (waste == '\n' && p - buffer + 1 == *length) {
        return 0;
      } else {
        return 1;
      }
    }
  }
  return 0;
}

int sum_numbers(int *buffer, int length) {
  int sum = 0;
  int miss = 0;
  for (int *p = buffer; p - buffer < length; p++) {
    if (*p % 2 == 0) {
      sum += *p;
      miss = 1;
    }
  }
  if (miss == 0) {
    sum = -1;
  }
  return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
  int cnt = 0;
  for (int *p = buffer; p - buffer < length; p++) {
    if (*p != 0 && number % *p == 0) {
      *(numbers + cnt) = *p;
      cnt++;
    }
  }
  return cnt;
}

void output(int *buffer, int length) {
  int summ = sum_numbers(buffer, length);
  printf("%d", summ);
  printf("\n");
  for (int i = 0; i < length; i++) {
    printf("%d", buffer[i]);
    if (i < length - 1) {
      printf(" ");
    }
  }
  printf("\n");
}
