#include <stdio.h>

int main()
{
    // Variables storing the details
    char name[] = "John Doe";
    int age = 16;
    char student_class[] = "11th";
    char division = 'A';
    char uin[] = "UIN12345678";

    // Printing the formatted output using escape sequences
    printf("=================================\n");
    printf("       STUDENT PROFILE       \n");
    printf("=================================\n");

    printf("Name:\t\t%s\n", name);
    printf("Age:\t\t%d\n", age);
    printf("Class:\t\t%s\n", student_class);
    printf("Division:\t%c\n", division);
    printf("UIN:\t\t%s\n", uin);

    printf("=================================\n");
    printf("Quote:\t\"Learning C is fun!\"\n");
    printf("Path:\tC:\\Programs\\Lab\n");
    printf("=================================\n");

    return 0;
}
