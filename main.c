#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "productLogic.c"
#include "authorization.c"
#include "admin.c"

int main()
{
    addStrings();

    userRoleChecker();

    Authorization();

    if (isAdmin)
    {
        printf("Hello admin!\n\n");
        printProducts();
        AdminLogic();
    }
    else
    {
        printf("----\nWelcome to the Grocery Store!\n----\n\n");
        printProducts();
    }
    return 0;
};