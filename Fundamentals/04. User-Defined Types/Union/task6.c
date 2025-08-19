#include <stdio.h>

	typedef union {
    		struct {
        		int hours;
        		int minutes;
    		} hms;
    		
			float totalHours;
	} Time;

	int main() {
    		Time t;
    		int choice;

    		printf("\tChoose input format:\n\n");
    		printf("1. Hours and minutes\n");
    		printf("2. Total hours (float)\n");
    
			printf("Choice: ");
    		scanf("%d", &choice);

    		if (choice == 1) {
        		printf("Enter hours: ");
        		scanf("%d", &t.hms.hours);
        
				printf("Enter minutes: ");
        		scanf("%d", &t.hms.minutes);

        		printf("\nYou entered: %d hours and %d minutes\n", t.hms.hours, t.hms.minutes);
        		printf("Memory as float: %.2f\n", t.totalHours);
    		}

    		else if (choice == 2) {
        		printf("Enter total hours (float): ");
        		scanf("%f", &t.totalHours);

        		printf("\nYou entered: %.2f total hours\n", t.totalHours);
        		printf("Memory as hours and minutes: %d hours, %d minutes\n", t.hms.hours, t.hms.minutes);
    		}
    		
		else
        		printf("Invalid choice!\n");
    		

    		return 0;
	}

