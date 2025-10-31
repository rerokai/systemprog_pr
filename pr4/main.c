#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
//подключаем всю хрень


int main() {
    int faild = 5;  // произвольный номер не открытого файла

    if (write(faild, "test\n", 5) == -1) { //пытаемся записать 5 байт текста в файл номер 5
  
        printf("Ошибка: %s (errno = %d)\n", strerror(errno), errno); //превращаем код ошибки в читаемый текст
    }

    return 0;
}