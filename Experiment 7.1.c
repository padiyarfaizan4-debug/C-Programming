#include <stdio.h>
int main()
{
    int n;
    int arr[100];
    printf("Enter the number of elements (1 to 100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100)
    {
        printf("Invalid number of elements!");
        return 0;
    }

    // Input array elements
    for (int i = 0; i < n; ++i)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Find sum, average, largest and smallest in a single pass
    int sum = 0, largest = arr[0], smallest = arr[0];
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (arr[i] > largest)
            largest = arr[i];
        if (arr[i] < smallest)
            smallest = arr[i];
    }

    // Print the array
    printf("\nArray elements: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);

    printf("\nSum      = %d", sum);
    printf("\nAverage  = %.2f", (float)sum / n);
    printf("\nLargest  = %d", largest);
    printf("\nSmallest = %d", smallest);

    // Sort a copy of the array in ascending order (bubble sort)
    int sorted[100];
    for (int i = 0; i < n; ++i)
        sorted[i] = arr[i];

    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if (sorted[j] > sorted[j + 1])
            {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }

    printf("\nSorted array: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", sorted[i]);

    printf("\n");
    return 0;
}
