#include <dirent.h>
#include <stdio.h>
#include <string.h>
#define ENG 26

int input(int *n);
void file_opener(const char *path, const char *mode);
void file_write(const char *path, const char *mode);
void encrypt(int shift, FILE *input, FILE *output);
void clear_file(const char *path);

int main() {
    int mode = 0;
    char file_name[256];
    char direct[1000];
    char file[3000];
    int num = 0;
    do {
        input(&mode);
        switch (mode) {
            case 1:
                scanf("%s", file_name);
                file_opener(file_name, "r");
                break;
            case 2:
                file_write(file_name, "a");
                break;
            case 3:
                printf("Введите директорию: ");
                scanf("%[^\n]", direct);
                printf("Введите кол-во сдвига: ");
                scanf("%d", &num);
                DIR *dir;
                dir = opendir(direct);
                if (dir != NULL) {
                    struct dirent *entry;
                    while ((entry = readdir(dir)) != NULL) {
                        if (entry->d_type == DT_REG) {
                            snprintf(file, sizeof(file), "%s/%s", direct, entry->d_name);
                            if (strstr(entry->d_name, ".c")) {
                                FILE *fp_inp = fopen(file, "r+"), *fp_out = fopen(file, "r+");
                                encrypt(num, fp_inp, fp_out);
                                fclose(fp_inp);
                                fclose(fp_out);
                            }
                            if (strstr(entry->d_name, ".h")) {
                                clear_file(file);
                            }
                        }
                    }
                }
                closedir(dir);
                break;
            case -1:
                break;
            default:
                printf("n/a\n");
                break;
        }
    } while (mode != -1);
    return 0;
}

int input(int *n) {
    char trash;
    scanf("%d%c", n, &trash);
    if (trash != '\n') {
        *n = -1;
    }
    return 0;
}

void file_opener(const char *path, const char *mode) {
    char buff[256];
    FILE *inp = fopen(path, mode);
    if (inp == NULL) {
        printf("n/a\n");
        int fclose(FILE * inp);
    } else {
        fseek(inp, 0, SEEK_END);
        long fileSize = ftell(inp);
        if (fileSize == 0) {
            printf("n/a\n");
            fclose(inp);
        } else {
            fseek(inp, 0, SEEK_SET);
            char ch;
            int i = 0;
            while ((ch = fgetc(inp)) != EOF) buff[i++] = ch;
            buff[i] = '\0';
            puts(buff);
            int fclose(FILE * inp);
        }
    }
}

void file_write(const char *path, const char *mode) {
    char buff[256];
    FILE *wrt = fopen(path, mode);
    if (wrt == NULL) {
        printf("n/a\n");
        int fclose(FILE * wrt);
    } else {
        fgets(buff, sizeof(buff), stdin);
        buff[strcspn(buff, "\n")] = 0;
        for (int i = 0; i < buff[i]; i++) {
            fputc(buff[i], wrt);
        }
        int fclose(FILE * wrt);
    }
}

void encrypt(int shift, FILE *input, FILE *output) {
    int c;
    while ((c = fgetc(input)) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A' + shift) % 26) + 'A';
        } else if (c >= 'a' && c <= 'z') {
            c = ((c - 'a' + shift) % 26) + 'a';
        }
        fputc(c, output);
    }
}

void clear_file(const char *path) {
    FILE *cls = fopen(path, "w");
    fclose(cls);
}
