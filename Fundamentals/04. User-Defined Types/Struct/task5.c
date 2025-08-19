#include <stdio.h>

	typedef struct {
    		int age;
   	 	float height;
		} Person;

	int main() {
    		Person person1, person2;

    		printf("\tEnter data for the first person\n\n");

    		printf("Age: ");
    		scanf("%d", &person1.age);
    
			printf("Height: ");
    		scanf("%f", &person1.height);

    		printf("\n\tEnter data for the second person\n\n");

    		printf("Age: ");
    		scanf("%d", &person2.age);
    
			printf("Height: ");
    		scanf("%f", &person2.height);

    		printf("\n");

    		if (person1.age > person2.age) 
        		printf("The first person is older.\n");
    		else if (person2.age > person1.age) 
        		printf("The second person is older.\n");
    		else 
        		printf("Both persons are of the same age.\n");
    		
    		return 0;
	}

