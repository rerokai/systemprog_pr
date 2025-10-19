#include <stdio.h>
#include <string.h>

int main() {
    FILE *in = fopen("file5.txt", "r"), *out = fopen("newfile5.txt", "w");
    if (!in || !out) return 1;
    
    char line[1000];
    
    while (fgets(line, sizeof(line), in)) {
        int len = strlen(line);
        if (line[len-1] == '\n') line[--len] = '\0';
        
        //пузырек
        for (int i = 0; i < len-1; i++)
            for (int j = i+1; j < len; j++)
                if (line[i] > line[j]) {
                    char temp = line[i];
                    line[i] = line[j];
                    line[j] = temp;
                }
        
        fprintf(out, "%s\n", line);
    }
    
    fclose(in); fclose(out);
    printf("белиберда готова\n");
    return 0;
}