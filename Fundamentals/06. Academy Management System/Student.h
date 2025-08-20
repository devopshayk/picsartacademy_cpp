#ifndef STUDENT_H
#define STUDENT_H

#include <stdbool.h>

	typedef enum { CPP, WEB, AI, DevHack } Languages;
	typedef enum { COMPUTER_SCIENCE, CORE_LANGUAGE, SPECIALTIES } Phase;

	typedef struct {
		char name[50];
		int id;
		Languages language;
		Phase phase;
		int monthExam[3];
		float totalScore;
		bool passed;     
	} Student;

	void addStudent(Student* s);
	void inputMonthlyExam(Student* s);
	void calculateTotal(Student* s);
	void checkPassed(Student* s);
	void printStudentReport(Student* s);
	int minScoreForThirdMonth(int month1, int month2);

#endif
