#include <stdio.h>

int   add(int a, int b);
int   sub(int a, int b);
int   mul(int a, int b);
float div(int a, int b);
int   rem(int a, int b);
int   and(int a, int b);
int   xor(int a, int b);
int    or(int a, int b);
int          not(int a);
int          inc(int a);
int          dec(int a);

int main()
{
    int id, a, b, result;
    printf("ID    Operation    Number of operands\n");
    printf("1     Add                 2\n");
    printf("2     Subtract            2\n");
    printf("3     Multiply            2\n");
    printf("4     Divide              2\n");
    printf("5     And                 2\n");
    printf("6     Or                  2\n");
    printf("7     Not                 1\n");
    printf("8     Xor                 2\n");
    printf("9     Remainder           2\n");
    printf("10    Increment           1\n");
    printf("11    Decrement           1\n");
    printf("\nEnter operation ID: ");
    scanf("%d", &id);
    switch (id)
    {
        case 1:
            printf("Enter the  first number: ");
            scanf("%d", &a);
            printf("Enter the  second number: ");
            scanf("%d", &b);
            result = add(a, b);
            printf("%d + %d =  %d\n", a, b, result);
            break;
        case 2:
            printf("Enter the  first number: ");
            scanf("%d", &a);
            printf("Enter the  second number: ");
            scanf("%d", &b);
            result = sub(a, b);
            printf("%d - %d =  %d\n", a, b, result);
            break;
        case 3:
            printf("Enter the  first number: ");
            scanf("%d", &a);
            printf("Enter the  second number: ");
            scanf("%d", &b);
            result = mul(a, b);
            printf("%d * %d =  %d\n", a, b, result);
            break;
        case 4:
            printf("Enter the  first number: ");
            scanf("%d", &a);
            printf("Enter the  second number: ");
            scanf("%d", &b);
            printf("%d / %d =  %.2f\n", a, b, div(a, b));
            break;
        case 5:
            printf("Enter the  first number: ");
            scanf("%d", &a);
            printf("Enter the  second number: ");
            scanf("%d", &b);
            result = and(a, b);
            printf("%d & %d =  %d\n", a, b, result);
            break;
        case 6:
            printf("Enter the  first number: ");
            scanf("%d", &a);
            printf("Enter the  second number: ");
            scanf("%d", &b);
            result = or(a, b);
            printf("%d | %d =  %d\n", a, b, result);
            break;
        case 7:
            printf("Enter the number: ");
            scanf("%d", &a);
            result = not(a);
            printf("~%d =  %d\n", a, result);
            break;
        case 8:
            printf("Enter the  first number: ");
            scanf("%d", &a);
            printf("Enter the  second number: ");
            scanf("%d", &b);
            result = xor(a, b);
            printf("%d ^ %d =  %d\n", a, b, result);
            break;
        case 9:
            printf("Enter the  first number: ");
            scanf("%d", &a);
            printf("Enter the  second number: ");
            scanf("%d", &b);
            result = rem(a, b);
            printf("%d %% %d =  %d\n", a, b, result);
            break;
        case 10:
            printf("Enter the number: ");
            scanf("%d", &a);
            result = inc(a);
            printf("%d++ =  %d\n", a, result);
            break;
        case 11:
            printf("Enter the number: ");
            scanf("%d", &a);
            result = dec(a);
            printf("%d-- =  %d\n", a, result);
            break;
        default:
            printf("Invalid operation\n");
            break;
    }
    return 0;
}

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
float div(int a, int b)
{
    return (float)a / b;
}
int rem(int a, int b)
{
    return a % b;
}
int and(int a, int b)
{
    return a & b;
}
int xor(int a, int b)
{
    return a ^ b;
}
int or(int a, int b)
{
    return a | b;
}
int not(int a)
{
    return ~a;
}
int inc(int a)
{
    return a++;
}
int dec(int a)
{
    return a--;
}