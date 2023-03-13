#include <stdio.h>

int main()
{
    int grade;
    printf("Please enter your grade: ");
    scanf("%d", &grade);
    if (grade >= 0 && grade < 50)
    {
        printf("You failed\n");
    }
    else if (grade >= 50 && grade < 65)
    {
        printf("Your rating is normal\n");
    }
    else if (grade >= 65 && grade < 75)
    {
        printf("Your rating is good\n");
    }
    else if (grade >= 75 && grade < 85)
    {
        printf("Your rating is very good\n");
    }
    else if (grade >= 85 && grade <= 100)
    {
        printf("Your rating is excellent\n");
    }
    else
    {
        printf("Please enter a valid grade!\n");
    }
    return 0;
}