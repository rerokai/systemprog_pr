//Даны два непустых файла. Определить номер строки и номер первого символа в этой строке, отличающего содержимое одного файла от другого. 
//Если содержимое файлов полностью совпадает или один файл является началом другого, то вывести соответствующие сообщения.

#include <stdio.h>
#include <string.h>

int main() {
    const char *filename1 = "file2.txt";
    const char *filename2 = "file3.txt";
    FILE *f1 = fopen(filename1, "r");
    FILE *f2 =fopen(filename2,"r");

    int line; int sim;

    while(1){

        char c1=fgetc(f1);
        char c2=fgetc(f2);

        if(c1!=c2){
            line++; //считает с нулевой строки поэтому +1
            printf("Различие на строке: %d \n", line, sim);
            break;
        }

        if (c1 == EOF) {
            printf("Файлы одинаковые\n");
            break;
        }

        if (c1 == '\n') {
            line++;
            sim = 1;
        } else {
            sim++;
        }
    }

    fclose(f1);
    fclose(f2);
    return 0;
}