#include <stdio.h>

	typedef struct {
		int length;
		int width;
	} Rectangle;

	
	int main() {
		int area = 0, perimeter = 0;
 
		Rectangle r;


		printf("\tWrite parameters to calculate the area of a rectanglei\n");

		puts("");

		printf("Write length for rectangle: ");
		scanf("%d", &r.length);
	
		printf("Write width for rectangle: ");
		scanf("%d", &r.width);

		area = r.length * r.width;

		puts("");



		printf("\tWrite parameters to calculate the perimeter of a rectangle\n");

		puts("");

        printf("Write length for rectangle: ");
        scanf("%d", &r.length);

        printf("Write width for rectangle: ");
        scanf("%d", &r.width);

        perimeter = 2 * (r.length + r.width);

		puts("");

		printf("Area of rectangle = %d\n", area);
		printf("Perimeter of rectangle = %d\n", perimeter);
	}
