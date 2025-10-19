//Создать файл, являющийся результатом конкатенации (слияния) других файлов. Имя файла-результата и имена соединяемых файлов задаются пользователем.
#include <stdio.h>
#include <string.h>

int main() {

    char filename1[100], filename2[100], result_filename[100];
    printf("Введите название первого файла: ");
    scanf("%99s", filename1);
    printf("Введите название второго файла: ");
    scanf("%99s", filename2);
    printf("Введите желаемое название нового файла: ");
    scanf("%99s", result_filename);

    FILE *file1, *file2, *result;
    file1=fopen(filename1, "r");
    file2=fopen(filename2, "r");
    result=fopen(result_filename, "w");

    if (file1 == NULL || file2==NULL ) { // проверка открытия файлов
        printf("Ошибка: не удалось открыть один из файлов \n");
        return 1;
        fclose(file1); fclose(file2);
    }
    int ch;

    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, result);
    }

     while ((ch = fgetc(file2)) != EOF) {
        fputc(ch, result);
    }
    
    fclose(file1);
    fclose(file2);
    fclose(result);

    printf("файлы объединены в %s\n", result_filename);

    return 0;    

}