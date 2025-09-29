#include <stdio.h>

#define MAX_STUDENTS 100
#define SUBJECTS 3

// Structure to store student details
struct Student {
    char name[50];
    float marks[SUBJECTS];
    float total;
    float average;
};

// Function declarations
void inputStudents(struct Student students[], int count);
void calculateGrades(struct Student students[], int count);
void displayStudents(const struct Student students[], int count);

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[MAX_STUDENTS];

    inputStudents(students, n);
    calculateGrades(students, n);
    displayStudents(students, n);

    return 0;
}

// Function to input student data
void inputStudents(struct Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", students[i].name); // Read full name with spaces

        for (int j = 0; j < SUBJECTS; j++) {
            printf("Marks for Subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }
    }
}

// Function to calculate total and average
void calculateGrades(struct Student students[], int count) {
    for (int i = 0; i < count; i++) {
        students[i].total = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            students[i].total += students[i].marks[j];
        }
        students[i].average = students[i].total / SUBJECTS;
    }
}

// Function to display student data
void displayStudents(const struct Student students[], int count) {
    printf("\n%-20s %-10s %-10s\n", "Name", "Total", "Average");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-20s %-10.2f %-10.2f\n", students[i].name,
               students[i].total, students[i].average);
    }
}
