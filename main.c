#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "utilities/utils.h"
#include "components/auth/authorization.h"
#include "components/products/productLogic.h"
#include "components/admin/admin.h"
#include "components/customer/customer.h"

int main()
{
    while (1) {

        
        if (userRole == -1) { // -1 is equivalent to null
            checkUserRole();
        }

        switch (userRole)
        {
        case 1:
            Authorization();
            if (userIsAdmin == 1) {
                AdminLogic();
            }
            break;
        case 0:
            handleUserChoice();
            break;
        }
    }

    return 0;
};