#include <stdio.h>
	
	void print_nums(int num);
		
	int main() {
		int n = 0;

		printf("Write num for print n-0 nums: ");
		scanf("%d", &n);

		printf("n-0 nums = ");
		print_nums(n);
		printf("\n");

		return 0;
	}


	void print_nums(int num) {
		printf("%d ", num);

		if(num == 0) return;

		print_nums(num - 1);
	}
