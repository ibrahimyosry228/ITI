#include <stdio.h>

int main()
{
    int id, pw;
    int i, j, n = 3, trials = 3;
    char* names[] = {"Ahmed", "Amr", "Wael"};
    int ids[] = {1234, 5678, 9870};
    int pws[] = {7788, 5566, 1122};
    printf("Please enter your ID: ");
    scanf("%d", &id);
    for (i = 0; i < n; i++)
    {
        if (ids[i] == id)
        {
            printf("Please enter password: ");
            scanf("%d", &pw);
            for(j = 0; j < trials; j++)
            {
                if (pws[i] == pw)
                {
                    printf("Welcome %s\n", names[i]);
                    return 0;
                }
                else if (j == trials - 1)
                {
                    printf("Incorrect password for 3 times, no more trials\n");
                }
                else
                {
                    printf("Try again: ");
                    scanf("%d", &pw);
                }
            }
            return 0;
        }
    }
    printf("You are not registered\n");
    return 0;
}