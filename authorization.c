#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "utils.h"

char password[9] = "Admin476";
char inputPassword[9];
int userRole = -1;
bool isAdmin;

void CheckUserRole()
{
    do
    {
        clearTerminal();

        printf("Welcome to the Grocery Store\n");
        printf("Select your identity...\n");
        printf("0 - Customer\n1 - Admin\n");

        scanf("%d", &userRole);
        while (getchar() != '\n');

        clearTerminal();

        if (userRole != 0 && userRole != 1)
        {
            printf("Please type the right option.\n");
            sleep(2);
            clearTerminal();
        }
    } while (userRole != 0 && userRole != 1);
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
        clearTerminal();
    }
    clearTerminal();
}