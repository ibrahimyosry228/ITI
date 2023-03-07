#include <stdio.h>

int main()
{
    int number, i;
    const int nums[10];
    for (i = 0; i < 10; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &nums[i]);
    }
    printf("Enter the value to search: ");
    scanf("%d", &number);
    for(i = 0; i < 10; i++)
    {
    if (number == nums[i])
    {
        printf("value exists at element number %d.\n", i + 1);
        return 0;
    }
    }
    printf("Value doesn't exist.\n");
    return 0;
}