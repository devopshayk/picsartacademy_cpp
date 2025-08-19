#include <stdio.h>

	typedef enum { RED, YELLOW, GREEN } TL;

	int main() {
		int num = 0;
		printf("Write num in range (0 - 2): ");
		scanf("%d", &num);

		TL color = num;

		switch(color) {
			case RED: printf("Red - Stop\n"); break;
			case YELLOW: printf("Yellow - Ready\n"); break;
			case GREEN: printf("GREEN - Go\n"); break;
			default: printf("Invalid signal\n");
		}
	}
