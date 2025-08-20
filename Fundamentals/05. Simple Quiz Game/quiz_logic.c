#include <stdio.h>
#include <ctype.h>


	extern char questions[][100];
	extern char optionsA[][50];
	extern char optionsB[][50];
	extern char optionsC[][50];
	extern char optionsD[][50];
	extern char correctAnswers[];


	int correctCount = 0;
	int wrongCount = 0;

	void playQuiz(int totalQuestions) {
    		correctCount = 0;
    		wrongCount = 0;
	

    		for (int i = 0; i < totalQuestions; i++) {
        		printf("\nQuestion %d:\n", i + 1);
        		printf("%s\n", questions[i]);
       			printf("A) %s\n", optionsA[i]);
        		printf("B) %s\n", optionsB[i]);
        		printf("C) %s\n", optionsC[i]);
        		printf("D) %s\n", optionsD[i]);

        		char answer;
        		printf("Your answer: ");
        		scanf(" %c", &answer);
        		answer = toupper(answer);

        		if (answer == correctAnswers[i]) {
            			printf("Correct!\n");
            			correctCount++;
        		} else {
            			printf("Wrong! Correct answer: %c\n", correctAnswers[i]);
            			wrongCount++;
        		}
    		}

    		printf("\nQuiz finished!\n");
    		printf("Correct answers: %d\n", correctCount);
    		printf("Wrong answers: %d\n", wrongCount);
	}

	int getCorrect() {
    		return correctCount;
	}

	int getWrong() {
    		return wrongCount;
	}

