#include <stdio.h>
#include <string.h>

int main(){

    printf("Замена слова Math на Code в файле file5.txt\n");
    char first_string[] = "math";
    char second_string[] = "code";

    const char *filename = "file5.txt";
    const char *temp_filename = "temp.txt";

    char line[1000];
    FILE *fp, *temp_fp;   
    fp = fopen(filename, "r");

    if (fp == NULL) { // Проверка открытия файла
        printf("Ошибка: не удалось открыть файл file2.txt\n");
        return 1;
    }

    temp_fp = fopen(temp_filename, "w");
    if (temp_fp == NULL) {
        printf("Ошибка: не удалось создать временный файл\n");
        fclose(fp);
        return 1;
    }
    
    
    while (fgets(line, 1000, fp) != NULL) {
        char *pos = line;
        char *found;
        
        
        while ((found = strstr(pos, first_string)) != NULL) {
            
            *found = '\0';
            fprintf(temp_fp, "%s", pos);
            fprintf(temp_fp, "%s", second_string);
            
        
            pos = found + strlen(first_string);
        }
        
       
        fprintf(temp_fp, "%s", pos);
    }
    

    fclose(fp);
    fclose(temp_fp);
    remove(filename);
    rename(temp_filename, filename);
    
    printf("замена завершена\n");
    
    return 0;

}