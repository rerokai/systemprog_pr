//Определить, сколько строк, состоящих из одного, двух, трех и т.д. символов, содержится в данном файле. Считать, что длина каждой
//строки – не более 30 символов. Имя файла задает пользователь.
#include <stdio.h>
#include <string.h>
#include <ctype.h> 


int main(){
    //char search_string[30];

    printf("Введите название документа: ");
    char search_file[100];

    scanf("%99s", search_file);
    const char *filename = search_file;
    FILE *sf = fopen(filename, "r");
    //char line[30];
    
    if (sf == NULL) { // Проверка открытия файла
        printf("Ошибка: не удалось открыть файл file2.txt\n");
        return 1;
    }

    int length_count[30 + 1] = {0};
    char line[30];
    int total_lines = 0;

    while (fgets(line, sizeof(line), sf) != NULL){
    
        int length = strlen(line);
        if (length <= 30) {
            length_count[length]++;
        } else {
            length_count[30]++;
        }
        total_lines++;
    }

    fclose(sf);

    for (int i = 1; i <= 30; i++) {
        if (length_count[i] > 0) {
            printf("длина %6d | количество %5d\n", i, length_count[i]);
        }
    }

    if (length_count[30] > 0) {
        printf("%6d+ | %5d\n", 30, length_count[30]);
    }
    
    return 0;
}