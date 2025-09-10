//Распечатать все строки данного файла(file2 как пример), содержащие заданную строку в качестве подстроки. Строка запрашивается у пользователя.
#include <stdio.h>
#include <string.h>

int main() {
    char search_string[1000];
    printf("Введите строку для поиска: ");
    scanf("%99s", search_string);

    const char *filename = "file2.txt";

    char line[1000];
    FILE *fp;
    
    fp = fopen(filename, "r");

    if (fp == NULL) { // Проверка открытия файла
        printf("Ошибка: не удалось открыть файл file2.txt\n");
        return 1;
    }
    
    while (fgets(line, 1000, fp) != NULL) {
        if (strstr(line, search_string) != NULL) {
            printf("%s", line);
        }
    }
    fclose(fp);
    return 0;
}


