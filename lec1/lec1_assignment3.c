#include <stdio.h>

int main()
{
    int n = 3;
    int a, b;
    printf("Please enter number a: ");
    scanf("%d", &a);
    printf("Please enter number b: ");
    scanf("%d", &b);
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a & b = %d\n", a & b);
    printf("a | b = %d\n", a | b);
    printf("a ^ b = %d\n", a ^ b);
    return 0;
}