//Дан файл f. Создать файл newf, полученный из файла f заменой всех его прописных букв соответствующими строчными.
#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main() {
    
    int ch;

    const char *filename = "f.txt";
    FILE *f1;
    f1 = fopen(filename, "r");
    if (f1 == NULL) { // Проверка открытия файла
        printf("Ошибка: не удалось открыть файл file2.txt\n");
        return 1;
    }

    const char *filen = "newf.txt";
    FILE *f2;
    f2 = fopen(filen, "w");

    while((ch=getc(f1))!= EOF)
    {
        fputc(tolower(ch), f2);
    }
    
    fclose(f1);
    fclose(f2);

    return 0;
    //прикол, tolower плохо работает на русском тексте
}
