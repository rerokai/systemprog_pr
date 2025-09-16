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

    if (fp == NULL) { // Проверка открытия файла
        printf("Ошибка: не удалось открыть файл file2.txt\n");
        return 1;
    }
    
    while((getc(fp))!= EOF){
        
        if(fscanf(fp, "%s", line) == 1){
            long lineint = strtol(line, NULL, 10);
            if(lineint%2==0 && lineint>=0){
                printf("Result: %ld\n", lineint);
            }
        }

    }
    
    fclose(fp);
    return 0;
    //какой же я гений, оно с первого раза РАБОТАЕТ

}