#include <stdio.h>

int main() {
    FILE * file = fopen("text.txt", "r");

    if (file == NULL) {
        printf("File not opened\n");
        return 1;
    }

    char buffer[256];
    int line = 1;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%d: %s", line, buffer);
        line++;
    }

    fclose(file);

    return 0;
}