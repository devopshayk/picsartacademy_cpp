#include <stdio.h>

	typedef struct {
    		int first;
    		int second;
	} Pair;

	int main() {
    		Pair p, temp;

    		printf("\tEnter two integer values\n\n");

    		printf("First value: ");
    		scanf("%d", &p.first);
    
			printf("Second value: ");
    		scanf("%d", &p.second);

    		temp.first = p.first;
    		temp.second = p.second;

    		p.first = temp.second;
    		p.second = temp.first;

    		printf("\nAfter swapping:\n\n");
    		printf("First value = %d\n", p.first);
    		printf("Second value = %d\n", p.second);

    		return 0;
	}

