#include <stdio.h>

	void swap(int * x_X, int * y_Y);

	int main() {
		int x, y;

		printf("\tWrite nums for X and Y for swap values\n\n");

		printf("Write num for X: ");
		scanf("%d", &x);

		printf("Write num for Y: ");
		scanf("%d", &y);

		swap(&x, &y);

		printf("\n");

		printf("Swaps values: X = %d, Y = %d\n", x, y);

		return 0;
	}

	void swap(int * x_X, int * y_Y) {
		int tmp = *x_X;
		*x_X = *y_Y;
		*y_Y = tmp;
	}
