#include <stdio.h>
#include <string.h>

#define SIZE 50

	void count_vowels_and_consonants(char arr[], int size, int* vowels, int* consonants);

	int main() {
    		char arr[SIZE];
    		int v = 0, c = 0;

    		fputs("Write text for counting vowels and consonants: ", stdout);
    		fgets(arr, SIZE, stdin);
    		arr[strcspn(arr, "\n")] = '\0'; 

    		count_vowels_and_consonants(arr, SIZE, &v, &c);

    		puts("");
    		printf("Vowels: %d\n", v);
    		printf("Consonants: %d\n", c);

    		return 0;
	}

	void count_vowels_and_consonants(char arr[], int size, int* vowels, int* consonants) {
    		*vowels = 0;
    		*consonants = 0;

    		for (int i = 0; i < size && arr[i] != '\0'; i++) {
            		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') (*vowels)++;
			else (*consonants)++;
        	}
    	}


