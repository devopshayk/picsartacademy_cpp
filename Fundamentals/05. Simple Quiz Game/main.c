#include <stdio.h>

#define MAX_QUESTIONS 5

	extern void playQuiz(int totalQuestions);
	extern int getCorrect();
	extern int getWrong();

	int main() {
    		int choice;

    		while (1) {
        		printf("\nQuiz Menu:\n");
        		printf("1) Play Quiz\n");
        		printf("2) Exit\n");
        		printf("Enter choice: ");
        		scanf("%d", &choice);

        		if (choice == 1) {
            			playQuiz(MAX_QUESTIONS);
        		} else if (choice == 2) {
            			printf("Goodbye!\n");
            			return 0;
        		} else {
            			printf("Invalid choice. Try again.\n");
        		}
    		}
	}

