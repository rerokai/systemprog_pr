//В файле записана непустая последовательность целых чисел (целое число – это последовательность десятичных цифр, начинающаяся
//знаком + или -). Создать новый файл, где все отрицательные числа заменены нулем.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    double search_num;

    const char *filename1 = "file4.txt";
    FILE *f1 = fopen(filename1, "r");
    char line[256];

    const char *filename2 = "newfile4.txt";
    FILE *f2 = fopen(filename2, "w");

    char *c1;
    long lineint;

    if (f1 == NULL) { // Проверка открытия файла
        printf("Ошибка: не удалось открыть файл file2.txt\n");
        return 1;
    }
    
    while (fscanf(f1, "%255s", line) == 1) {
        long lineint = strtol(line, NULL, 10);
        if (lineint < 0) {
            fprintf(f2, "0 ");
        } else {
            fprintf(f2, "%ld ", lineint);
        }
    }

    
    fclose(f1);
    fclose(f2);
    return 0;
    

}