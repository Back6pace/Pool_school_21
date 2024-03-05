#include "s21_string.h"

#include <stdio.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();

int main() {
    func();
    return 0;
}

void s21_strlen_test() {
    printf("Test 1 - strlen\n");
    char* str1 = "Hello world!";
    printf("Вход - %s - ", str1);
    int test1 = s21_strlen(str1);
    if (test1 == 12) {
        printf("Выход - %d - ", test1);
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char* str2 = "";
    printf("Вход - %s - ", str2);
    int test2 = s21_strlen(str2);
    if (test2 == 0) {
        printf("Выход - %d - ", test2);
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char* str3 = NULL;
    printf("Вход - %s - ", str3);
    int test3 = s21_strlen(str3);
    if (test3 == -1) {
        printf("Выход - %d - ", test3);
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcmp_test() {
    printf("Test 2 - strcmp\n");
    char* test1_str1 = "Hello";
    char* test1_str2 = "Hello";
    printf("Вход - %s - %s\n", test1_str1, test1_str2);
    int test1 = s21_strcmp(test1_str1, test1_str2);
    if (test1 == 0) {
        printf("Выход - %d - ", test1);
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char* test2_str1 = "Hello";
    char* test2_str2 = "Hell";
    printf("Вход - %s - %s\n", test2_str1, test2_str2);
    int test2 = s21_strcmp(test2_str1, test2_str2);
    if (test2 > 0) {
        printf("Выход - %d - ", test2);
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char* test3_str1 = "Man";
    char* test3_str2 = "Women";
    printf("Вход - %s - %s\n", test3_str1, test3_str2);
    int test3 = s21_strcmp(test3_str1, test3_str2);
    if (test3 < 0) {
        printf("Выход - %d - ", test3);
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char* test4_str1 = NULL;
    char* test4_str2 = NULL;
    printf("Вход - %s - %s\n", test4_str1, test4_str2);
    int test4 = s21_strcmp(test4_str1, test4_str2);
    if (test4 == -2) {
        printf("Выход: Веддено не верное значение NULL\n");
        printf("SUCCESS\n");
    } else {
        if (test4 == 0) {
            printf("Выход - %d - ", test4);
            printf("SUCCESS\n");
        } else {
            printf("FAIL\n");
        }
    }
}

void s21_strcpy_test() {
    printf("Test 3 - strcpy\n");
    char test1_str1[50] = "";
    char* test1_str2 = "Bye";
    printf("Вход - %s - %s\n", test1_str1, test1_str2);
    s21_strcpy(test1_str1, test1_str2);
    if (s21_strcmp(test1_str1, test1_str2) == 0) {
        printf("Выход - %s - ", test1_str1);
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char test2_str1[50] = "BOT";
    char* test2_str2 = "Wow";
    printf("Вход - %s - %s\n", test2_str1, test2_str2);
    s21_strcpy(test2_str1, test2_str2);
    if (s21_strcmp(test2_str1, test2_str2) == 0) {
        printf("Выход - %s - ", test2_str1);
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char test3_str1[50] = "";
    char* test3_str2 = NULL;
    printf("Вход - %s - %s\n", test3_str1, test3_str2);
    int test3 = s21_strcpy(test3_str1, test3_str2);
    if (test3 == 1) {
        printf("Выход: Веддено не верное значение NULL\n");
        printf("SUCCESS\n");
    } else {
        if (s21_strcmp(test3_str1, test3_str2) == 0) {
            printf("Выход - %s - ", test3_str1);
            printf("SUCCESS\n");
        } else {
            printf("FAIL\n");
        }
    }
}

void s21_strcat_test() {
    printf("Test 4 - strcat\n");
    char test1_str1[50] = "Akuna";
    char* test1_str2 = "Matata";
    printf("Вход - %s - %s\n", test1_str1, test1_str2);
    int test4 = s21_strcat(test1_str1, test1_str2);
    if (test4 == 1) {
        printf("Выход - %s - ", test1_str1);
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char test2_str1[50] = "";
    char* test2_str2 = "Matata";
    printf("Вход - %s - %s\n", test2_str1, test2_str2);
    int tot = s21_strcat(test2_str1, test2_str2);
    if (tot == 1) {
        printf("Выход - %s - ", test2_str1);
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char test3_str1[50] = "Akuna";
    char* test3_str2 = NULL;
    printf("Вход - %s - %s\n", test3_str1, test3_str2);
    int res = s21_strcat(test3_str1, test3_str2);
    if (res == 1) {
        printf("Выход: Веддено не верное значение NULL\n");
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}
