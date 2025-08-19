#include <stdio.h>

	typedef struct {
    		float mathGrade;
    		float physicsGrade;
    		float chemistryGrade;
	} Student;

	int main() {
    		Student s;
    		float average = 0.0;

    		printf("\tEnter grades for the student\n\n");

    		printf("Math grade: ");
    		scanf("%f", &s.mathGrade);

    		printf("Physics grade: ");
    		scanf("%f", &s.physicsGrade);

    		printf("Chemistry grade: ");
    		scanf("%f", &s.chemistryGrade);

    		average = (s.mathGrade + s.physicsGrade + s.chemistryGrade) / 3;

    		printf("\nAverage grade = %.2f\n", average);

    		return 0;
	}

