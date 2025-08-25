// Minimal demo of linking against a static library built from object files
#include <stdio.h>
#include "mylib.h"

int main(void) {
    int a = 6;
    int b = 4;

    printf("sum(%d, %d) = %d\n", a, b, sum(a, b));
    printf("diff(%d, %d) = %d\n", a, b, diff(a, b));
    return 0;
}


