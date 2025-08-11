#include <stdio.h>

	void print_binary(int num);

	int main() {	
		int num = 13;

		print_binary(num);

		return 0;
	}

	void print_binary(int num) {
		if(num > 1) print_binary(num / 2);

		printf("%d", num % 2);
	}
