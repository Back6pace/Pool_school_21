#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

struct my_struct {
    int year;
    int mounth;
    int day;
    int hour;
    int minut;
    int second;
    int status;
    int code;
};

struct my_struct read_record_from_file(FILE *pfile, int index);

void read_file(FILE *file);
void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
int compare(const struct my_struct s1, const struct my_struct s2);
void sort(FILE *file, int n);
