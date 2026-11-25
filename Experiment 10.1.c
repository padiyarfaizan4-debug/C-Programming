#include <stdio.h>
int main()
{
    int num1, num2, sum;
    int *ptr1, *ptr2;


    ptr1 = &num1; // ptr1 stores the address of num1
    ptr2 = &num2; // ptr2 stores the address of num2


    printf("Enter any two numbers: ");
    scanf("%d%d", ptr1, ptr2);


    sum = *ptr1 + *ptr2;


    printf("Sum = %d\n", sum);

    // Show that the pointers really refer to the original variables
    printf("\nAddress of num1 = %p, value = %d\n", (void *)ptr1, *ptr1);
    printf("Address of num2 = %p, value = %d\n", (void *)ptr2, *ptr2);

    // Modify the variables through the pointers
    *ptr1 = *ptr1 * 2;
    *ptr2 = *ptr2 * 2;
    printf("\nAfter doubling through pointers:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
