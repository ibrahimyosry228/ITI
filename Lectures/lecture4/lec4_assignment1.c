#include <stdio.h>

int maximum(int* nums, int size);
int minimum(int* nums, int size);

int main()
{
    int i, n = 4;
    
    int nums[n];
    int max, min;
    for (i = 0; i < n; i++)
    {
        printf("Please enter value number %d: ", i + 1);
        scanf("%d", &nums[i]);
    }
    max = maximum(nums, n);
    min = minimum(nums, n);
    printf("The maximum of the %d numbers is: %d\n", n, max);
    printf("The minimum of the %d numbers is: %d\n", n, min);
    return 0;
}

int maximum(int* nums, int size)
{
    int max, i;
    max = nums[0];
    for (i = 1; i < size; i++)
    {
        max = nums[i] > max ? nums[i] : max;
    }
    return max;
}

int minimum(int* nums, int size)
{
    int min, i;
    min = nums[0];
    for (i = 1; i < size; i++)
    {
        min = nums[i] < min ? nums[i] : min;
    }
    return min;
}