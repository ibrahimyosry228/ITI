#include <stdio.h>

int main()
{
    int i, n = 3;
    int nums[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &nums[i]);
    }
    int max = nums[0] >= nums[1] && nums[0] >= nums[2] ? nums[0] : nums[1] >= nums[2] ? nums[1] : nums[2];
    printf("Maximum number is: %d\n", max);
    return 0;
}