#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "utils.h"
#include "productLogic.c"
#include "authorization.c"
#include "admin.c"

bool start;

int main()
{
    start = true;
    addStrings();

    do
    {
        if (userRole == -1) {
            CheckUserRole();
        }
    
        if (!isAdmin) {
            Authorization();
        }
    
        switch (isAdmin)
        {
        case true:
            AdminLogic();
            break;
    
        default:
            printf("----\nWelcome to the Grocery Store!\n----\n\n");
            printProducts();
            break;
        }

    } while (start);

    return 0;
};