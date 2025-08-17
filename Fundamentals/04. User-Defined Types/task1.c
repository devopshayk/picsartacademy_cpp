#include <stdio.h>

	typedef enum { WINTER, SPRING, SUMMER, FALL } seasons;


	int main() {
		int month = 0;
		printf("Write month number(1-12) for detected season: ");
		scanf("%d", &month);

		seasons season;

		if (month == 12 || month == 1 || month == 2) season = WINTER;
		else if (month >= 3 && month <= 5) season = SPRING;
		else if (month >= 6 && month <= 8) season = SUMMER;
		else if (month >= 9 && month <= 11) season = FALL;
		else {
			printf("Not valid num for month: %d, write num in range (0 - 12)", month);
			return 0;
		}

		switch(season) {
			case WINTER: printf("Season is WINTER\n"); break;
			case SPRING: printf("Season is SPRING\n"); break;
			case SUMMER: printf("Season is SUMMER\n"); break;
			case FALL: printf("Season is FALL\n"); break;
		}
		
		return 0;
	}	
