#include <stdio.h>

int main()
{
    int id, pw, user_id, user_pw;
    id = 289; pw = 12959165;
    printf("Please enter your id: ");
    scanf("%d", &user_id);
    if (user_id == id)
    {
        printf("Please enter your password: ");
        scanf("%d", &user_pw);
        if (user_pw == pw)
        {
            printf("ID: %d\n", user_id);
        }
        else
        {
            printf("Incorrect password\n");
        }
    }
    else
    {
        printf("Incorrect ID\n");
    }
    return 0;
}