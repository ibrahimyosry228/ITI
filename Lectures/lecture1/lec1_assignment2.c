#include <stdio.h>

int main()
{
    int n = 3;
    int nums[n], i;
    for (i = 0; i < n; i++)
    {
        printf("Please enter number %d: ", i + 1);
        scanf("%d", &nums[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("number %d: %d\n", n -i, nums[n - 1 - i]);
    }
    return 0;
}