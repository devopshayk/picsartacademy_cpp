#include <stdio.h>

int main() {
    FILE * file = fopen("text.txt", "r");

    if (!file) {
        printf("File not opened\n");
        return 1;
    }

    char buffer[256];

    long pos1 = ftell(file);
    printf("Position before fgets: %ld\n", pos1);

    fgets(buffer, sizeof(buffer), file);
    printf("First read: %s", buffer);

    long pos2 = ftell(file);
    printf("Position after fgets: %ld\n", pos2);

    printf("Bytes moved: %ld\n", pos2 - pos1);

    fseek(file, 0, SEEK_SET);

    fgets(buffer, sizeof(buffer), file);
    printf("Second read: %s", buffer);

    fclose(file);

    return 0;
}