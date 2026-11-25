#include <stdio.h>
// Function to swap two memory contents
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Function to reverse the array through pointers
void reverse(int array[], int array_size)
{
    // pointer1 pointing at the beginning of the array
    int *pointer1 = array,
        // pointer2 pointing at end of the array
        *pointer2 = array + array_size - 1;
    while (pointer1 < pointer2) {
        swap(pointer1, pointer2);
        pointer1++;
        pointer2--;
    }
}

// Print an array using pointer traversal
void printArray(int array[], int array_size)
{
    int *p;
    for (p = array; p < array + array_size; p++)
        printf("%d ", *p);
    printf("\n");
}

int main()
{
    int n, i;
    int arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid number of elements!\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Direct demonstration of swap() on two variables
    printf("\nBefore swap: arr[0] = %d, arr[n-1] = %d\n", arr[0], arr[n - 1]);
    swap(&arr[0], &arr[n - 1]);
    printf("After  swap: arr[0] = %d, arr[n-1] = %d\n", arr[0], arr[n - 1]);

    printf("\nOriginal array: ");
    printArray(arr, n);

    // Reverse the array in place
    reverse(arr, n);

    printf("Reversed array: ");
    printArray(arr, n);

    return 0;
}
