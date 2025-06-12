#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "../products/productLogic.h"
#include "../auth/authorization.h"
#include "customer.h"
#include "../../utilities/utils.h"

#define PRODUCT_COUNT 10
#define NAME_LEN 9

int userChoices[10] = {0};
int userChoice = 0;
int isBasket = 0;

void Purchase() {
    int input;
    int overall;

    clearTerminal();
    
    printf("You have bought!\n");
    for (int i = 0; i < 10; i++) {
        if (userChoices[i]) {
            int cost = userChoices[i] * price[i];

            overall += cost;
            printf("$%d | quantity: %d | %s\n", cost, userChoices[i], name[i]);
            
            quantity[i] = quantity[i] - userChoices[i];
        }
    }
    
    
    printf("\nOverall: $%d", overall);
    
    printf("\n\n-----\n");
    printf("Thank you for your purchase!\n");
    printf("See you soon!\n");
    printf("-----\n");
    
    printf("\n0 - exit");
    printf("\n1 - go to the store");
    printf("\nChoice: ");
    
    scanf("%d", &input);
    while (getchar() != '\n');

    switch (input)
    {
    case 0:
        clearTerminal();
        exit(0);
    case 1:
        memset(userChoices, 0, sizeof(userChoices));
        isBasket = 0;
        userChoice = 0;
        overall = 0;
        break;
    default:
        printf("\n**Invalid choice");
        sleep(2);
        break;
    }
}

void showBasket() {
    #define PRODUCT_COUNT 10

    int input;
    bool hasProducts = false;
    int overall = 0;
    
    clearTerminal();
    
    if (!isBasket) {
        
        printf("Your products:\n");
        for (int i = 0; i < PRODUCT_COUNT; i++) {
            if (userChoices[i]) {
                int cost = userChoices[i] * price[i];
                
                hasProducts = true;
                overall += cost;
                printf("$%d | quantity: %d | %s\n", cost, userChoices[i], name[i]);
            }
        }
        
        if (!hasProducts) {
            clearTerminal();
            printf("The basket is empty");
            userChoice = 0;
            sleep(2);
            return;
        }
        
    
        printf("\nOverall: $%d\n", overall);
        
        printf("\n0 - Buy \n");
        printf("1 - Continue shopping\n");
        
        printf("\nChoice: ");
        scanf("%d", &input);
        while (getchar() != '\n');
        
    }
    
    switch (input)
    {
    case 0:
        isBasket = 1;
        Purchase();
        break;

    case 1:
        userChoice = 0;
        break;
    
    default:
        printf("\n**Invalid choice");
        sleep(2);
        break;
    }

}

void handleUserChoice(){
    #define PRODUCT_COUNT 10

    int ID, amount;
    int input;
    
    if (!userChoice) {

        clearTerminal();
        printf("----\nWelcome to the Grocery Store!\n----\n\n");

        printProducts();
    
        printf("\nEnter the details of the product that you want to buy... ");
    
        printf("\nID: ");
        int isIDValid = scanf("%d", &ID);
        while (getchar() != '\n');
    
        if ( !isIDValid || !(ID >= 0 && ID <= PRODUCT_COUNT)) {
            printf("\n**Incorrect ID number.");
            sleep(2);
            return;
        }
    
        printf("Quantity: ");
        int isQuantityValid = scanf("%d", &amount);
        while (getchar() != '\n');
    
        userChoices[ID] += amount;
        bool isAvailable = (quantity[ID] - userChoices[ID]) >= 0;
    
        if ( !isQuantityValid || !(amount >= 0 && amount <= 100)) {
            userChoices[ID] -= amount;
            printf("\n**Invalid amount.");
            sleep(2);
            return;
        } else if (!isAvailable) {
            userChoices[ID] -= amount;
            printf("**Sorry, only %d items are available.", quantity[ID]);
            sleep(2);
            return;
        }
    
    
        printf("\n0 - to proceed to the cart.");
        printf("\n1 - to buy more products.\n");
        printf("2 - to go back to the main menu.\n");
        printf("3 - to exit the store.\n");
        printf("\nChoice: ");
        
        scanf("\n%d", &input);
        while (getchar() != '\n');
    }

    switch (input)
    {
    case 0:
        userChoice = 1;
        showBasket();
        break;
    case 1:
        break;
    case 2:
        userChoices[ID] -= amount;
        userRole = -1;
        break;
    case 3:
        clearTerminal();
        exit(0);
    default:
        userChoices[ID] -= amount;
        printf("\n**Invalid choice.");
        sleep(2);
        break;
    }

}