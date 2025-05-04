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
        if (userRole == -1) {
            CheckUserRole();
        }
    
        Authorization();
    
        if (userRole == 0) {
            handleUserChoice();
        } else if (isAdmin == 1) {
            AdminLogic();
        }
    }

    return 0;
};