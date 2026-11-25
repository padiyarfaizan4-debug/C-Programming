#include <stdio.h>
// Recursive function to find the nth Fibonacci number
int fibonacci(int n) {
    // Base case 1: if n is 0, return 0
    if (n <= 0) {
        return 0;
    }
    // Base case 2: if n is 1, return 1
    else if (n == 1) {
        return 1;
    }
    // Recursive case: sum of the two preceding numbers
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive number of terms.\n");
        return 1;
    }

    if (n > 35)
        printf("Note: the recursive version is slow for large n.\n");

    printf("Fibonacci series up to %d terms:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d", fibonacci(i));
        if (i < n - 1)
            printf(", ");
    }
    printf("\n");

    printf("The %dth Fibonacci number is %d\n", n, fibonacci(n));

    return 0;
}
