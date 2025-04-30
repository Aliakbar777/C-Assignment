#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int ID, amount, finish, adminChoice;

extern int userRole;

int restockConfirmation() {
    int input;
    bool hasProducts = false;
    int overall = 0;
    
    clearTerminal();
    
    if (!isBasket) {
        
        printf("Your products:\n");
        for (int i = 0; i < 10; i++) {
            if (choices[i]) {
                int cost = choices[i] * price[i];
                
                hasProducts = true;
                overall += cost;
                printf("+%d | quantity: %d | %s\n", choices[i], choices[i], name[i]);
            }
        }
        
        if (!hasProducts) {
            clearTerminal();
            printf("**You have not yet choosen products to restock");
            userChoice = 0;
            sleep(2);
            return;
        }
        
        printf("\n0 - Restock \n");
        printf("1 - Continue restocking\n");
        
        printf("\nChoice: ");
        scanf("%d", &input);
        while (getchar() != '\n');
        
    }
    
    
    if (input == 0) {
        isBasket = 1;
        return;
    } else if (input == 1) {
        userChoice = 0;
        return;
    } else {
        printf("**Invalid choice");
        sleep(2);
        return;
    }
}

void AdminLogic()
{
    int choices[10] = {0};

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
    
        choices[ID] += amount;
    
        if (isQuantityValid != 1 || !(amount > 0 && amount <= 100)) {
            printf("\n**Invalid amount.");
            sleep(2);
            return;
        }
    
        printf("\n0 - to proceed to the confirmation.");
        printf("\n1 - to choose more products to restock.\n");
        printf("\nChoice: ");
        int isChoiceValid = scanf("\n%d", &finish);
        while (getchar() != '\n');

        if (!isChoiceValid || !(finish == 1 || finish == 0)) {
            choices[ID] -= amount;
            printf("\n**Invalid choice.");
            sleep(2);
            return;
        }
    
        if (finish == 0) {
            userChoice = 1;
            restockConfirmation(choices);
            return;
        } else if (finish == 1) {
            return;
        }
    }

    
}
