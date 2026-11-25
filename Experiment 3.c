#include <stdio.h>
#include <stdlib.h>

// Define maximum limits
#define MAX_STUDENTS 100

// Structure to store student details
struct Student {
    int id;
    char name[50];
    float marks;
    char grade;
};

// Discard any characters left on the current input line, so a rejected
// entry cannot be mistaken for the next field that is read
void discardLine(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

// Convert a percentage into a letter grade
char calculateGrade(float marks) {
    if (marks >= 90) return 'A';
    if (marks >= 75) return 'B';
    if (marks >= 60) return 'C';
    if (marks >= 40) return 'D';
    return 'F';
}

// Print one student record in a fixed-width row
void printStudent(const struct Student *s) {
    printf("%-6d %-25s %8.2f %6c\n", s->id, s->name, s->marks, s->grade);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice, searchId, found, i;

    do {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Add student\n");
        printf("2. Display all students\n");
        printf("3. Search student by ID\n");
        printf("4. Delete student by ID\n");
        printf("5. Show class statistics\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            discardLine();
            choice = -1;
            printf("Invalid choice!\n");
            continue;
        }

        switch (choice) {
        case 1:
            if (count >= MAX_STUDENTS) {
                printf("Record is full!\n");
                break;
            }
            printf("Enter ID: ");
            if (scanf("%d", &students[count].id) != 1) {
                printf("Invalid ID!\n");
                discardLine();
                break;
            }

            // Reject duplicate IDs
            found = 0;
            for (i = 0; i < count; i++) {
                if (students[i].id == students[count].id) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                printf("A student with this ID already exists!\n");
                discardLine();
                break;
            }

            printf("Enter name (single word): ");
            scanf("%49s", students[count].name);
            printf("Enter marks (0-100): ");
            scanf("%f", &students[count].marks);
            if (students[count].marks < 0 || students[count].marks > 100) {
                printf("Invalid marks!\n");
                discardLine();
                break;
            }
            students[count].grade = calculateGrade(students[count].marks);
            count++;
            printf("Student added successfully.\n");
            break;

        case 2:
            if (count == 0) {
                printf("No records to display.\n");
                break;
            }
            printf("\n%-6s %-25s %8s %6s\n", "ID", "NAME", "MARKS", "GRADE");
            printf("--------------------------------------------------\n");
            for (i = 0; i < count; i++)
                printStudent(&students[i]);
            break;

        case 3:
            printf("Enter ID to search: ");
            scanf("%d", &searchId);
            found = 0;
            for (i = 0; i < count; i++) {
                if (students[i].id == searchId) {
                    printf("\n%-6s %-25s %8s %6s\n", "ID", "NAME", "MARKS", "GRADE");
                    printf("--------------------------------------------------\n");
                    printStudent(&students[i]);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Student with ID %d not found.\n", searchId);
            break;

        case 4:
            printf("Enter ID to delete: ");
            scanf("%d", &searchId);
            found = -1;
            for (i = 0; i < count; i++) {
                if (students[i].id == searchId) {
                    found = i;
                    break;
                }
            }
            if (found == -1) {
                printf("Student with ID %d not found.\n", searchId);
                break;
            }
            // Shift the remaining records one position to the left
            for (i = found; i < count - 1; i++)
                students[i] = students[i + 1];
            count--;
            printf("Record deleted.\n");
            break;

        case 5:
            if (count == 0) {
                printf("No records available.\n");
                break;
            } else {
                float total = 0, highest = students[0].marks, lowest = students[0].marks;
                for (i = 0; i < count; i++) {
                    total += students[i].marks;
                    if (students[i].marks > highest) highest = students[i].marks;
                    if (students[i].marks < lowest) lowest = students[i].marks;
                }
                printf("\nNumber of students : %d\n", count);
                printf("Class average      : %.2f\n", total / count);
                printf("Highest marks      : %.2f\n", highest);
                printf("Lowest marks       : %.2f\n", lowest);
            }
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
