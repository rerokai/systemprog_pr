#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

int main() {
    while (1) {
        struct stat st;

        if (stat("current.log", &st) == 0) {
            time_t created = st.st_ctime;

            char newname[256];
            snprintf(newname, sizeof(newname), "logs/log_%ld.log", created);

            
            char cmd_move[512];
            snprintf(cmd_move, sizeof(cmd_move),
                     "mv current.log %s", newname);
            system(cmd_move);

            //надеюсь оно работает
            char cmd_gzip[512];
            snprintf(cmd_gzip, sizeof(cmd_gzip),
                     "gzip %s", newname);
            system(cmd_gzip);
        }

        sleep(5); 
    }
    return 0;
}