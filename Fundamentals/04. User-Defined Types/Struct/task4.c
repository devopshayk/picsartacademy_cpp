#include <stdio.h>
#include <math.h>

	typedef struct {
    		float x;
    		float y;
	} Point;

	int main() {
    		Point p1, p2;
    		float distance;

    		printf("\tEnter coordinates for the first point\n\n");

    		printf("x: ");
    		scanf("%f", &p1.x);
    
			printf("y: ");
    		scanf("%f", &p1.y);

    		printf("\n\tEnter coordinates for the second point\n\n");

    		printf("x: ");
    		scanf("%f", &p2.x);
    
			printf("y: ");
    		scanf("%f", &p2.y);

    		distance = sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));

    		printf("\nDistance between points = %.2f\n", distance);

    		return 0;
	}

