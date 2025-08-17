#include <stdio.h>

	typedef enum {SMALL, MEDIUM, LARGE} Size;

	int main() {
    		int prices[] = {500, 800, 1200};
    		
		printf("Menu:\n");
    		printf("0 - SMALL : %d\n", prices[SMALL]);
    		printf("1 - MEDIUM: %d\n", prices[MEDIUM]);
    		printf("2 - LARGE : %d\n", prices[LARGE]);

    		int choice;
    		printf("\nChoose your pizza size (0-2): ");
    		scanf("%d", &choice);

    		if (choice >= SMALL && choice <= LARGE) printf("Price of chosen pizza: %d\n", prices[choice]);
     		else printf ("Invalid choice!\n");
   
		return 0;
	}
 
