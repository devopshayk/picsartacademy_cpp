#include <stdio.h>
#include "Student.h"

int main() {
	
	Student st[10];
	
	addStudent(&st[0]);
	
	inputMonthlyExam(&st[0]);	
	
	calculateTotal(&st[0]);

	checkPassed(&st[0]);

	printStudentReport(&st[0]);
	
	int month1 = st[0].monthExam[0];
    int month2 = st[0].monthExam[1];
    int minMonth3 = minScoreForThirdMonth(month1, month2);
    
	printf("Minimum score needed for third month to pass: %d\n", minMonth3);
	
	return 0;
}
