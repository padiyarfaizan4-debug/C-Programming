#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Define structure for Employee
struct Employee {
    int emp_id;
    char name[50];
    char designation[30];
    float salary;
};


// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();


// File used to persist the records between runs
#define FILE_NAME "employees.dat"

// Discard any characters left on the current input line, so a rejected
// entry cannot be mistaken for the next field that is read
void discardLine() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

// Number of records currently held in the file
int countRecords() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
        return 0;

    struct Employee e;
    int count = 0;
    while (fread(&e, sizeof(struct Employee), 1, fp) == 1)
        count++;

    fclose(fp);
    return count;
}

void addEmployee() {
    struct Employee e;
    FILE *fp;

    printf("\nEnter employee ID: ");
    if (scanf("%d", &e.emp_id) != 1) {
        printf("Invalid employee ID!\n");
        discardLine();
        return;
    }

    // Reject duplicate IDs
    fp = fopen(FILE_NAME, "rb");
    if (fp != NULL) {
        struct Employee temp;
        while (fread(&temp, sizeof(struct Employee), 1, fp) == 1) {
            if (temp.emp_id == e.emp_id) {
                printf("An employee with ID %d already exists!\n", e.emp_id);
                fclose(fp);
                discardLine();
                return;
            }
        }
        fclose(fp);
    }

    printf("Enter name: ");
    scanf("%49s", e.name);

    printf("Enter designation: ");
    scanf("%29s", e.designation);

    printf("Enter salary: ");
    scanf("%f", &e.salary);

    if (e.salary < 0) {
        printf("Salary cannot be negative!\n");
        discardLine();
        return;
    }

    fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        printf("Error: could not open file for writing.\n");
        return;
    }

    fwrite(&e, sizeof(struct Employee), 1, fp);
    fclose(fp);

    printf("Employee record added successfully.\n");
}

void displayEmployees() {
    struct Employee e;
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("\nNo records found. Add an employee first.\n");
        return;
    }

    printf("\n%-8s %-25s %-20s %10s\n", "ID", "NAME", "DESIGNATION", "SALARY");
    printf("---------------------------------------------------------------\n");

    int found = 0;
    while (fread(&e, sizeof(struct Employee), 1, fp) == 1) {
        printf("%-8d %-25s %-20s %10.2f\n",
               e.emp_id, e.name, e.designation, e.salary);
        found++;
    }

    fclose(fp);

    if (found == 0) {
        printf("No records found.\n");
    } else {
        printf("---------------------------------------------------------------\n");
        printf("Total employees: %d\n", found);
    }
}

void searchEmployee() {
    struct Employee e;
    int id, found = 0;
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("\nNo records found. Add an employee first.\n");
        return;
    }

    printf("\nEnter employee ID to search: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(struct Employee), 1, fp) == 1) {
        if (e.emp_id == id) {
            printf("\nRecord found:\n");
            printf("ID          : %d\n", e.emp_id);
            printf("Name        : %s\n", e.name);
            printf("Designation : %s\n", e.designation);
            printf("Salary      : %.2f\n", e.salary);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("No employee found with ID %d.\n", id);
}

int main() {
    int choice;

    do {
        printf("\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add employee\n");
        printf("2. Display all employees\n");
        printf("3. Search employee by ID\n");
        printf("4. Count records\n");
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
            addEmployee();
            break;
        case 2:
            displayEmployees();
            break;
        case 3:
            searchEmployee();
            break;
        case 4:
            printf("\nNumber of employee records: %d\n", countRecords());
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
