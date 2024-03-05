#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#include <string.h>
#endif
#include "state_sort.h"

int main() {
    char path1[256];
    int mode;
    int n = 0;
    scanf("%s", path1);
    char path[256] = "../";
    strcat(path, path1);
    printf("%s", path);
    FILE *file = fopen(path, "rb+");
    struct my_struct s3;
    if (file != NULL) {
        scanf("%d", &mode);
        switch (mode) {
            case 0:
                read_file(file);
                break;
            case 1:
                n = get_records_count_in_file(file);
                sort(file, n);
                read_file(file);
                break;
            case 2:
                scanf("%d %d %d %d %d %d %d %d", &s3.year, &s3.mounth, &s3.day, &s3.hour, &s3.minut,
                      &s3.second, &s3.status, &s3.code);
                n = get_records_count_in_file(file);
                write_record_in_file(file, &s3, n);
                n = get_records_count_in_file(file);
                sort(file, n);
                read_file(file);
                break;
            default:
                printf("n/a\n");
                break;
        }
    } else {
        printf("n/a\n");
    }
    fclose(file);
    return 0;
}

void read_file(FILE *file) {
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    if (fileSize == 0) {
        printf("n/a\n");
    } else {
        fseek(file, 0, SEEK_SET);
        struct my_struct records[get_records_count_in_file(file)];
        size_t num_records;

        num_records = fread(records, sizeof(struct my_struct), get_records_count_in_file(file), file);
        fclose(file);

        for (size_t i = 0; i < num_records; i++) {
            printf("%d %d %d %d %d %d %d %d\n", records[i].year, records[i].mounth, records[i].day,
                   records[i].hour, records[i].minut, records[i].second, records[i].status, records[i].code);
        }
    }
}

int compare(const struct my_struct s1, const struct my_struct s2) {
    int res = 0;
    do {
        if (s1.year != s2.year) {
            res = (s1.year > s2.year) ? 1 : -1;
            continue;
        }
        if (s1.mounth != s2.mounth) {
            res = (s1.mounth > s2.mounth) ? 1 : -1;
            continue;
        }
        if (s1.day != s2.day) {
            res = (s1.day > s2.day) ? 1 : -1;
            continue;
        }
        if (s1.hour != s2.hour) {
            res = (s1.hour > s2.hour) ? 1 : -1;
            continue;
        }
        if (s1.minut != s2.minut) {
            res = (s1.minut > s2.minut) ? 1 : -1;
            continue;
        }
        if (s1.second != s2.second) {
            res = (s1.second > s2.second) ? 1 : -1;
            continue;
        }
    } while (0);
    return res;
}

void sort(FILE *file, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            struct my_struct s = read_record_from_file(file, j);
            struct my_struct s2 = read_record_from_file(file, j + 1);

            if (compare(s, s2) == 1) {
                swap_records_in_file(file, j, j + 1);
            }
        }
    }
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