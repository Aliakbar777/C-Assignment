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

    CheckUserRole();

    Authorization();

    switch (isAdmin)
    {
    case true:
        printf("Hello admin!\n\n");
        printProducts();
        AdminLogic();
        break;

    default:
        printf("----\nWelcome to the Grocery Store!\n----\n\n");
        printProducts();
        break;
    }

    return 0;
};