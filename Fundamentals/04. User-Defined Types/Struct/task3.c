#include <stdio.h>

	typedef struct {
    		float balance;
    		int ownerId;
	} Account;

	int main() {
    		Account acc1, acc2;
    		float transferAmount;

    		printf("\tEnter data for first account\n\n");

    		printf("Owner ID: ");
    		scanf("%d", &acc1.ownerId);
    
			printf("Balance: ");
			scanf("%f", &acc1.balance);

    		printf("\n\tEnter data for second account\n\n");

    		printf("Owner ID: ");
    		scanf("%d", &acc2.ownerId);
    
			printf("Balance: ");
    		scanf("%f", &acc2.balance);

    		printf("\nBalances before transfer:\n");
    		printf("Account %d: %.2f\n", acc1.ownerId, acc1.balance);
    		printf("Account %d: %.2f\n", acc2.ownerId, acc2.balance);

    		transferAmount = acc1.balance * 0.2;
    		acc1.balance -= transferAmount;
    		acc2.balance += transferAmount;

    		printf("\nBalances after transferring 20%% from first to second account:\n");
    		printf("Account %d: %.2f\n", acc1.ownerId, acc1.balance);
    		printf("Account %d: %.2f\n", acc2.ownerId, acc2.balance);

    		return 0;
	}

