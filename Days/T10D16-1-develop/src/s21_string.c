#include "s21_string.h"

#include <stdio.h>

int s21_strlen(char *str) {
    int len = 0;
    if (str == NULL) {
        len = -1;
    } else {
        for (int i = 0; str[i] != '\0'; i++) {
            len++;
        }
    }
    return len;
}

int s21_strcmp(char *str1, char *str2) {
    int miss = -2;
    if (str1 != NULL && str2 != NULL) {
        for (; *str1 && *str1 == *str2; str1++, str2++) {
        }
        int res = *str1 - *str2;
        if (res > 0)
            miss = 1;
        else if (res < 0)
            miss = -1;
        else
            miss = 0;
    }
    return miss;
}

int s21_strcpy(char *from, char *to) {
    if (to != NULL) {
        if (s21_strlen(from) > s21_strlen(to)) {
            while (*from != '\0') {
                *(from++) = *(to++);
            }
        } else {
            while (*to != '\0') {
                *(from++) = *(to++);
            }
        }
    }
    return 1;
}

int s21_strcat(char *str1, char *str2) {
    int res = 1;
    if (str1 != NULL && str2 != NULL) {
        while (*str1 != '\0') {
            str1++;
        }
        while (*str2) {
            *str1 = *str2;
            str1++;
            str2++;
        }
        *str1 = '\0';
        res = 1;
    }
    return res;
}
