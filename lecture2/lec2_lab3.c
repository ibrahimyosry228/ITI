#include <stdio.h>

int main()
{
    int num;
    printf("Please enter a number: ");
    scanf("%d", &num);
    if (num % 2)
    {
        printf("Number is odd\n");
    }
    else
    {
        printf("Number is even\n");
    }
    return 0;
}