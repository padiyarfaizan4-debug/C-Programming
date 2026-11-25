#include <stdio.h>

int main() {
    int start, end, temp, sum = 0;

    // Input lower and upper limits
    printf("Enter starting number: ");
    scanf("%d", &start);

    printf("Enter ending number: ");
    scanf("%d", &end);

    // Swap if starting number is greater than ending number
    if (start > end) {
        temp = start;
        start = end;
        end = temp;
    }

    // Add every number in the (corrected) range
    for (temp = start; temp <= end; temp++) {
        sum += temp;
    }

    printf("\nSum of numbers from %d to %d = %d\n", start, end, sum);

    // The same result using the arithmetic progression formula
    printf("Verification using n(n+1)/2 formula = %d\n",
           (end * (end + 1) / 2) - ((start - 1) * start / 2));

    return 0;
}
