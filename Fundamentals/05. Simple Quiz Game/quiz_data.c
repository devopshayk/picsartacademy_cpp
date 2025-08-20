#define MAX_QUESTIONS 5
#define MAX_TEXT_LEN 100
#define MAX_OPTION_LEN 50

	 char questions[MAX_QUESTIONS][MAX_TEXT_LEN] = {
    		"What is the capital of France?",
    		"What is 2 + 2?",
    		"What color is the sky?",
    		"Which animal barks?",
    		"Which planet is known as the Red Planet?"
	};

	char optionsA[MAX_QUESTIONS][MAX_OPTION_LEN] = {"London", "3", "Green", "Cat", "Earth"};
	char optionsB[MAX_QUESTIONS][MAX_OPTION_LEN] = {"Paris", "4", "Blue", "Dog", "Mars"};
	char optionsC[MAX_QUESTIONS][MAX_OPTION_LEN] = {"Rome", "5", "Red", "Bird", "Venus"};
	char optionsD[MAX_QUESTIONS][MAX_OPTION_LEN] = {"Berlin", "6", "Yellow", "Cow", "Jupiter"};

	char correctAnswers[MAX_QUESTIONS] = {'B', 'B', 'B', 'B', 'B'};
