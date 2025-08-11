#include <stdio.h>
	
	void print_nums(int num);

	int main() {
		int n = 0;

		printf("Write num for print 0-n nums: ");
		scanf("%d", &n);

		printf("0-n nums = ");
		print_nums(n);
		printf("\n");

		return 0;
	} 


	void print_nums(int num) {
		if(num < 0) return;

		print_nums(num - 1);

		printf("%d ", num);
	}
