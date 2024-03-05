#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#include <string.h>
#endif
#include "state_sort.h"

int get_data(FILE *pfile, int *error);

int main() {
    char path1[256];
    scanf("%s", path1);
    char path[256] = "../";
    strcat(path, path1);
    FILE *pfile = fopen(path, "rb+");
    if (pfile != NULL) {
        int error = 0;
        get_data(pfile, &error);
        if (error) {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    fclose(pfile);
    return 0;
}

int get_data(FILE *pfile, int *error) {
    int year, month, day;
    if (scanf("%d.%d.%d", &day, &month, &year) == 3) {
        if ((day > 0 && day <= 31) && (month > 0 && month <= 12) && (year >= 1920 && year < 2021)) {
            int count = get_records_count_in_file(pfile);
            for (int i = 0; i < count; i++) {
                struct my_struct s = read_record_from_file(pfile, i);
                if (s.day == day && s.mounth == month && s.year == year) {
                    printf("%d", s.code);
                }
            }
        } else {
            *error = 1;
        }
    } else {
        *error = 1;
    }
    return *error;
}

struct my_struct read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(struct my_struct);
    fseek(pfile, offset, SEEK_SET);

    struct my_struct record;
    fread(&record, sizeof(struct my_struct), 1, pfile);

    rewind(pfile);
    return record;
}

void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index) {
    int offset = index * sizeof(struct my_struct);
    fseek(pfile, offset, SEEK_SET);

    fwrite(record_to_write, sizeof(struct my_struct), 1, pfile);

    fflush(pfile);
    rewind(pfile);
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    struct my_struct record1 = read_record_from_file(pfile, record_index1);
    struct my_struct record2 = read_record_from_file(pfile, record_index2);

    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int get_records_count_in_file(FILE *pfile) {
    return get_file_size_in_bytes(pfile) / sizeof(struct my_struct);
}