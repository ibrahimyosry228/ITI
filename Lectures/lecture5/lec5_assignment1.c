#include <stdio.h>

int max(int* arr, int size);
int min(int* arr, int size);

int main()
{
    int n = 10, i;
    int nums[n];
    for (i = 0; i < n; i++)
    {
        printf("Pleas enter number[%d]: ", i + 1);
        scanf("%d",  &nums[i]);
    }
    printf("The maximum number in the array is: %d\n", max(nums, n));
    printf("The minimum number in the array is: %d\n", min(nums, n));
    return 0;
}

int max(int* arr, int size)
{
    int maximum = arr[0], i;
    for (i = 1; i < size; i++)
    {
        maximum = arr[i] > maximum ? arr[i] : maximum;
    }
    return maximum;
}
int min(int* arr, int size)
{
    int minimum = arr[0], i;
    for (i = 1; i < size; i++)
    {
        minimum = arr[i] > minimum ? minimum : arr[i];
    }
    return minimum;
}
