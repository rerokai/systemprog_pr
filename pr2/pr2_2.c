// Определить, какой символ чаще других встречается в данном файле.
#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main() {
    //char search_string[1000];
    //printf("Введите строку для поиска: ");
    //scanf("%99s", search_string);

    int frequency[256] = {0};
    int ch;

    const char *filename = "file2.txt";
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) { // Проверка открытия файла
        printf("Ошибка: не удалось открыть файл file2.txt\n");
        return 1;
    }

    while((ch=getc(fp))!= EOF)
        {
            int lower_ch = tolower(ch); //ну чтобы и нижн и верх регистр считало
            if (ch >= 0 && ch < 256){
                 if (isalpha(lower_ch)) 
                {
                    frequency[lower_ch]++; 
                }
            }
        }
    fclose(fp);

    int max_freq = 0;
    int max_char = 0;

    for (int i = 0; i < 256; i++) {
        if (frequency[i] > max_freq) {
            max_freq = frequency[i];
            max_char = i; 
        }
    }

    if (isprint(max_char)) {
        printf("Самый частый символ: %c", max_char);
        printf(" (встречается %d раз)\n", max_freq);
    }
    
    return 0;
}
