#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
    char name[50];
    int age;
    double height;
} Person;


// Constructors
void person_def_init(Person *);
void person_param_init(Person *, char *, int, double);

// Getters
const char * getName(Person *);
int getAge(const Person * const p);
double getHeight(Person *);

// Setters
void setName(Person *, const char *);
void setAge(Person *, int);
void setHeight(Person *, double);

// PrintStudentInfo
void printInfo(Person *);
void printInfoHeight(Person *, bool);


void person_def_init(Person * p) {
    strcpy(p -> name, "Hayk");
    p -> age = 0;
    p -> height = 0.0; 
}


void person_param_init(Person * p, char * newName, int newAge, double newHeight) {
    strncpy(p -> name, newName, sizeof(p->name) - 1);
    p -> name[sizeof(p -> name) - 1] = '\0';

    p -> age = newAge;
    p -> height = newHeight;
}


const char * getName(Person * p) { return p->name; }
int getAge(const Person * const p) { return p->age; }
double getHeight(Person * p) { return p->height; }


void setName(Person * p, const char * newName) {
    strncpy(p -> name, newName, sizeof(p -> name) - 1);
    p -> name[sizeof(p -> name) - 1] = '\0';
}


void setAge(Person * p, int newAge) {
    p -> age = newAge;
}


void setHeight(Person * p, double newHeight) {
    p -> height = newHeight;
}


void printInfo(Person *p) {
    printf("\tPerson's All Info\n\n");

    printf("Name is: %s\n", p -> name);
    printf("Name is: %d\n", p -> age);
    printf("Name is: %.2f\n", p -> height);
}

void printInfoHeight(Person * p, bool condition) {
    if(condition) {
        printf("Person's Height = %.2f\n", p -> height);
    } else {
        printf("Not valid condition for height: \n");
    }
}


int main() {
    Person p;

    person_param_init(&p, "Hayk", 16, 156.1);
    printInfo(&p);

    return 0;
}