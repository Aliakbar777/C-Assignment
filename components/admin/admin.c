#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "../products/productLogic.h"
#include "../auth/authorization.h"
#include "admin.h"
#include "../../utilities/utils.h"

int ID, amount, adminChoice;
int adminChoices[10] = {0};

void restockConfirmation(int adminChoices[]) {
    int input;
    bool hasProducts = false;
    int overall = 0;
    
    clearTerminal();
        
    printf("Choosen products to restock:\n");
    for (int i = 0; i < 10; i++) {
        if (adminChoices[i]) {
            int cost = adminChoices[i] * price[i];
            
            hasProducts = true;
            overall += cost;
            printf("quantity: +%d | %s\n", adminChoices[i], name[i]);
        }
    }
    
    if (!hasProducts) {
        clearTerminal();
        printf("**You have not yet choosen products to restock");
        adminChoice = 0;
        sleep(2);
        return;
    }
    
    printf("\n0 - Restock \n");
    printf("1 - Continue restocking\n");
    
    printf("\nChoice: ");
    scanf("%d", &input);
    while (getchar() != '\n');
        
    
    switch (input)
    {
        case 0:
            for (int i = 0; i < 10; i++) {
                if (adminChoices[i]) {
                    quantity[i] += adminChoices[i];
                }
            }
            userRole = 1;
            adminChoice = 0;
            printf("\nYou have successfully restocked products.");
            sleep(2);
            break;
        case 1:
            adminChoice = 0;
            break;
        default:
            printf("**Invalid choice");
            sleep(2);
            break;
    }


}

void AdminLogic() {
    int input;
    
    if (!adminChoice) {
        
        clearTerminal();
        
        printf("Hello admin!\n\n");
        printProducts();
        
        printf("\nEnter the details of the product that you want to restock...\n");
        
        printf("ID: ");
        int isIDValid = scanf("%d", &ID);
        while (getchar() != '\n');
    
        if (isIDValid != 1 || !(ID >= 0 && ID <= 9)) {
            printf("\n**Incorrect ID number.");
            sleep(2);
            return;
        }
    
        printf("Quantity: ");
        int isQuantityValid = scanf("%d", &amount);
        while (getchar() != '\n');
    
        adminChoices[ID] += amount;
    
        if (isQuantityValid != 1 || !(amount > 0 && amount <= 100)) {
            adminChoices[ID] -= amount;
            printf("\n**Invalid amount.");
            sleep(2);
            return;
        }
    
        printf("\n0 - to proceed to the confirmation.");
        printf("\n1 - to choose more products to restock.\n");
        printf("2 - to go back to the main menu.\n");
        printf("3 - to exit the store.\n");
        printf("\nChoice: ");
        int isChoiceValid = scanf("\n%d", &input);
        while (getchar() != '\n');

        if (!isChoiceValid || !(input <= 0 || input >= 3)) {
            adminChoices[ID] -= amount;
            printf("\n**Invalid choice.");
            sleep(2);
            return;
        }

        switch (input)
        {
        case 0:
            adminChoice = 1;
            restockConfirmation(adminChoices);
            break;
        case 1:
            break;
        case 2:
            adminChoices[ID] -= amount;
            userRole = -1;
            break;
        case 3:
            clearTerminal();
            exit(0);
        }
    }
}
