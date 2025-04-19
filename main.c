#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "utils.h"
#include "authorization.c"
#include "productLogic.c"
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

        Authorization();
    
        if (isAdmin == -1) {
            Basket();
        } else if (isAdmin == 1) {
            AdminLogic();
        }

    } while (start);

    return 0;
};