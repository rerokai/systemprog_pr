#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    while (1) {
        FILE *f = fopen("current.log", "a");
        if (!f) {
            perror("fopen");
            return 1;
        }

        time_t now = time(NULL);
        struct tm *tm_info = localtime(&now);

        char buffer[32];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);

        fprintf(f, "%s\n", buffer);
        fclose(f);

        sleep(1);
    }
    return 0;
}