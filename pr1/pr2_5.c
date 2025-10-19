// В файле записана непустая последовательность целых чисел (целое число – это последовательность десятичных цифр, возможно
//начинающаяся знаком + или -). Определить, сколько четных положительных чисел содержится в файле.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    double search_num;

    const char *filename = "file4.txt";
    FILE *fp = fopen(filename, "r");
    char line[256];

    char *c1;
    long lineint;
    int count = 0;

    if (fp == NULL) { // Проверка открытия файла
        printf("Ошибка: не удалось открыть файл file2.txt\n");
        return 1;
    }
    
    while (fscanf(fp, "%255s", line) == 1) {
        long number = strtol(line, NULL, 10);
        if (number > 0 && number % 2 == 0) {
            count++;
            printf("Найдено четное положительное число: %ld\n", number);
        }
    }
    
    fclose(fp);
    printf("Всего четных положительных чисел: %d\n", count);
    return 0;

    

}