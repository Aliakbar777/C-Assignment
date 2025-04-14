#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

char password[9] = "Admin476";
char inputPassword[9];
int userRole;
bool isAdmin;

void CheckUserRole()
{
    printf("Type the right option...\n");
    printf("0 - Customer\n1 - Admin\n");
    scanf("%d", &userRole);
    while (getchar() != '\n')
        ;
    system("cls");
}

void Authorization()
{
    if (userRole == 0)
    {
        return;
    }

    while (!isAdmin)
    {
        printf("Type the admin password\n");
        printf("<--- type \"back\" to proceed to the store\n");
        printf("password: ");

        fgets(inputPassword, sizeof(inputPassword), stdin);
        inputPassword[strcspn(inputPassword, "\n")] = '\0';

        if (strcmp(password, inputPassword) == 0)
        {
            isAdmin = true;
        }
        else if (strcmp(inputPassword, "back") == 0)
        {
            break;
        }
        else
        {
            isAdmin = false;
            printf("The password is incorrect!\n\n");
        };

        sleep(2);
        system("cls");
    }
    system("cls");
}