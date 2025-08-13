#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

	bool contains(int arr[], int size, int num);

	int main() {
		int arr[SIZE];
		int s_num;

		printf("Write %d elements for array: ", SIZE);
		for(int i = 0; i < SIZE; i++) scanf("%d", &arr[i]);

		printf("Write num for search in array: ");
		scanf("%d", &s_num);

		puts("");
		printf("%s", contains(arr, SIZE, s_num) ? "Yes" : "No");
		puts("");

		return 0;
	}

	bool contains(int arr[], int size, int num) {
		for(int i = 0; i < size; i++) {
			if(arr[i] == num) return true;
		}

		return false;
	}
