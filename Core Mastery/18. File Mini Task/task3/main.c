#include <stdio.h>
#include <string.h>

int main() {
    FILE * in = fopen("text.txt", "r");

    if (!in) {
        printf("Input file error\n");
        return 1;
    }

    FILE * out = fopen("output.txt", "w");

    if (!out) {
        printf("Output file error\n");
        fclose(in);
        return 1;
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), in)) {
        if (strchr(buffer, 'X') == NULL) {
            fputs(buffer, out);
        }
    }

    fclose(in);
    fclose(out);

    return 0;
}