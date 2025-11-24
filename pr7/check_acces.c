#include <stdio.h>
#include <errno.h>
#include <string.h>


int main() {
    const char *filename = "/home/user/sysprog/systemprog_pr/systemprog_pr/pr7/test_file.txt";

    printf("=== Проверяем доступ к %s ===\n", filename);

    // Проверка чтения
    FILE *f = fopen(filename, "r");
    if (f) {
        printf("ЧТЕНИЕ: доступ разрешён.\n");
        fclose(f);
    } else {
        printf("ЧТЕНИЕ: ошибка (%s).\n", strerror(errno));
    }

    // Проверка записи
    f = fopen(filename, "a");
    if (f) {
        printf("ЗАПИСЬ: доступ разрешён.\n");
        fprintf(f, "check\n");
        fclose(f);
    } else {
        printf("ЗАПИСЬ: ошибка (%s).\n", strerror(errno));
    }

    return 0;
}