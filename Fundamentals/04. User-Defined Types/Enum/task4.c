#include <stdio.h>

	typedef enum { READ = 1, WRITE = 2, EXECUTE = 4 } Permisions;

	int main() {
		int perm = 0;
		printf("Write permision in range (1 - 7): ");
		scanf("%d", &perm);

		if (perm >= 1 && perm <= 7) {	
			if (perm & READ) printf("Read is set\n");
			if (perm & WRITE) printf("Write is set\n");
			if (perm & EXECUTE) printf("Execute is sset\n");
		} else 
			printf("Not valid permision\n");


		return 0;
	}
