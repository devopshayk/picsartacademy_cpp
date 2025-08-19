#include <stdio.h>
#define PI 3.14

	typedef struct {
    		float radius;
	} Circle;

	int main() {
    		Circle c;
    		float circumference, area;

    		printf("\tEnter the radius of the circle\n\n");

    		printf("Radius: ");
    		scanf("%f", &c.radius);

    		circumference = 2 * PI * c.radius;
    		area = PI * c.radius * c.radius;

    		printf("\nCircumference = %.2f\n", circumference);
    		printf("Area = %.2f\n", area);

    		return 0;
	}

