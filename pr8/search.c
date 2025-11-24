#include <unistd.h>   // read, write, close
#include <fcntl.h>    // open
#include <string.h>  
#include <stdio.h>    
#include <stdlib.h>  

int main() {
    char search[256];

    write(1, "Введите строку для поиска: ", 28);
    int len = read(0, search, sizeof(search)-1);
    if (len <= 0) return 1;

    // Удаляем \n в конце, если есть
    if (search[len-1] == '\n') {
        search[len-1] = '\0';
    } else {
        search[len] = '\0';
    }

    int fd = open("file2.txt", O_RDONLY);
    if (fd < 0) {
        write(1, "Ошибка: не удалось открыть файл\n", 33);
        return 1;
    }

    char buf[1024];
    char line[2048];
    int line_len = 0;

    while (1) {
        int r = read(fd, buf, sizeof(buf));
        if (r < 0) {
            write(1, "Ошибка чтения файла\n", 21);
            close(fd);
            return 1;
        }
        if (r == 0) break; // EOF

        for (int i = 0; i < r; i++) {
            char c = buf[i];

            if (c == '\n') {
                line[line_len] = '\0';

                if (strstr(line, search) != NULL) {
                    write(1, line, line_len);
                    write(1, "\n", 1);
                }

                line_len = 0;
            } else {
                if (line_len < (int)sizeof(line)-1) {
                    line[line_len++] = c;
                }
            }
        }
    }

    close(fd);
    return 0;
}