#include <stdio.h>

int main() {
    float physics, chemistry, maths;
    float total, average;

    // Input marks for PCM
    printf("Enter Physics marks (out of 100): ");
    scanf("%f", &physics);

    printf("Enter Chemistry marks (out of 100): ");
    scanf("%f", &chemistry);

    printf("Enter Mathematics marks (out of 100): ");
    scanf("%f", &maths);

    // Validate mark inputs
    if (physics < 0 || physics > 100 ||
        chemistry < 0 || chemistry > 100 ||
        maths < 0 || maths > 100) {
        printf("Error: marks must be between 0 and 100.\n");
        return 1;
    }

    // Calculate total and average
    total = physics + chemistry + maths;
    average = total / 3.0f;

    // Display the result using formatted output
    printf("\n---------------------------------\n");
    printf("Subject\t\tMarks\n");
    printf("---------------------------------\n");
    printf("Physics\t\t%6.2f\n", physics);
    printf("Chemistry\t%6.2f\n", chemistry);
    printf("Mathematics\t%6.2f\n", maths);
    printf("---------------------------------\n");
    printf("Total\t\t%6.2f / 300\n", total);
    printf("Average\t\t%6.2f %%\n", average);
    printf("---------------------------------\n");

    // Assign a remark based on the average
    if (average >= 75)
        printf("Result: Distinction\n");
    else if (average >= 60)
        printf("Result: First Class\n");
    else if (average >= 40)
        printf("Result: Pass\n");
    else
        printf("Result: Fail\n");

    return 0;
}
