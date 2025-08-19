#include <stdio.h>

	typedef union {
		int number;
		char flag;
	} Flag;

	int main() {
		Flag f;

		printf("Enteran integer: ");
		scanf("%d", &f.number);

		printf("\nnumber = %d\n", f.number);
		printf("flag (first byte of number as ASCCII) = %c\n", f.flag);
	
		return 0;
	}
