#include <stdio.h>
#include <string.h>
#include "Student.h"

	void addStudent(Student* s) {
		printf("Write name for Student: ");
		scanf("%s", s->name);

		printf("Write ID for Student: ");
		scanf("%d", &s->id);

		int lang = 0;
		printf("Choose language (0.CPP 1.WEB 2.AI 3.DevHack): ");
		scanf("%d", &lang);

		s->language = (Languages)lang;
		s->totalScore = 0.0;
		s->passed = false;
		s->phase = COMPUTER_SCIENCE;
	}

	void inputMonthlyExam(Student* s) {
		for (int i = 0; i < 3; i++) {
			printf("Write score for month %d: ", i + 1);
			scanf("%d", &s->monthExam[i]);
		}
	}

	void calculateTotal(Student* s) {
		s->totalScore = 0;
		for (int i = 0; i < 3; i++) {
			s->totalScore += s->monthExam[i] * 0.1;
		} 
	}

	void checkPassed(Student* s) {
		s->passed = (s->totalScore >= 80);
	}

	void printStudentReport(Student* s) {
		printf("\nStudent's name: %s\n", s->name);
		printf("Student's ID: %d\n", s->id);

		printf("Language: ");
		switch (s->language) {
			case CPP: printf("CPP\n"); break;
			case WEB: printf("WEB\n"); break;
			case AI: printf("AI\n"); break;
			case DevHack: printf("DevHack\n"); break;
		}

		printf("Phase: ");
		switch (s->phase) {
			case COMPUTER_SCIENCE: printf("COMPUTER_SCIENCE\n"); break;
			case CORE_LANGUAGE: printf("CORE_LANGUAGE\n"); break;
			case SPECIALTIES: printf("SPECIALTIES\n"); break;
		}

		printf("Monthly Exams: ");
		for (int i = 0; i < 3; i++) printf("%d ", s->monthExam[i]);
		printf("\n");

		printf("Total Score = %.2f\n", s->totalScore);
		printf("Result: %s\n", s->passed ? "Passed" : "Failed");
	}

	int minScoreForThirdMonth(int month1, int month2) {
		float totalSoFar = (month1 + month2) * 0.1;
		int minScore = (int)((80 - totalSoFar) / 0.1 + 0.999);
		if (minScore > 100) minScore = 100;
		if (minScore < 0) minScore = 0;
		return minScore;
	}
