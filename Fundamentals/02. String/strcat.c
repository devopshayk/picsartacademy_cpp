#include <stdio.h>
#include <ctype.h>

void transform(char *str, char (*func)(char)) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = func(str[i]);
    }
}

char to_upper(char c) {
    if (c >= 'a' && c <= 'z') return c - ('a' - 'A');
    return c;
}

char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') return c + ('a' - 'A');
    return c;
}

int main() {
    char str[100];
    int choice;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Choose transformation:\n");
    printf("0 - To Uppercase\n");
    printf("1 - To Lowercase\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    if (choice == 0) {
        transform(str, to_upper);
    } else if (choice == 1) {
        transform(str, to_lower);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    printf("Transformed string: %s\n", str);

    return 0;
}
