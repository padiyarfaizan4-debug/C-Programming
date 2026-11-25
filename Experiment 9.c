#include <stdio.h>

// Define the structure student_record
struct student_record {
    char name[50];
    int roll_number;
    float total_marks;
};

int main() {
    struct student_record students[5];
    int i, topper_index = 0;

    // Read data for 5 students
    printf("--- Enter Details for 5 Students ---\n\n");
    for (i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);

        printf("  Name: ");
        scanf("%49s", students[i].name);

        printf("  Roll number: ");
        scanf("%d", &students[i].roll_number);

        printf("  Total marks (out of 500): ");
        scanf("%f", &students[i].total_marks);

        // Track the student with the highest marks as we read
        if (students[i].total_marks > students[topper_index].total_marks)
            topper_index = i;

        printf("\n");
    }

    // Display the whole class list
    printf("--- Student Records ---\n");
    printf("%-6s %-25s %10s %8s\n", "ROLL", "NAME", "MARKS", "PERCENT");
    printf("--------------------------------------------------------\n");
    for (i = 0; i < 5; i++) {
        printf("%-6d %-25s %10.2f %7.2f%%\n",
               students[i].roll_number,
               students[i].name,
               students[i].total_marks,
               students[i].total_marks / 500.0 * 100.0);
    }

    // Display the topper
    printf("\n--- Topper of the Class ---\n");
    printf("Name        : %s\n", students[topper_index].name);
    printf("Roll number : %d\n", students[topper_index].roll_number);
    printf("Total marks : %.2f out of 500\n", students[topper_index].total_marks);
    printf("Percentage  : %.2f%%\n",
           students[topper_index].total_marks / 500.0 * 100.0);

    // Class average
    float sum = 0;
    for (i = 0; i < 5; i++)
        sum += students[i].total_marks;
    printf("\nClass average: %.2f out of 500 (%.2f%%)\n",
           sum / 5.0, sum / 5.0 / 500.0 * 100.0);

    return 0;
}
