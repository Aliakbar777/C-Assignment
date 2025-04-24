#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

char name[10][9];
int price[] = {2, 2, 1, 3, 4, 3, 7, 6, 4, 5};
int quantity[] = {20, 30, 30, 30, 20, 20, 15, 30, 20, 40};

int choices[10] = {0};
int overall = 0;

int userChoice = 0;
int isBasket = 0;

void addStrings()
{
    strcpy(name[0], "Carrot");
    strcpy(name[1], "Apple");
    strcpy(name[2], "Potato");
    strcpy(name[3], "Cucumber");
    strcpy(name[4], "Flour");
    strcpy(name[5], "Bread");
    strcpy(name[6], "Beef");
    strcpy(name[7], "Sausage");
    strcpy(name[8], "Rice");
    strcpy(name[9], "Ketchup");
};

int printProducts()
{
    int productId;

    printf("Groceries:\n");
    for (productId = 0; productId < 10; productId++)
    {
        printf("ID: %d | Available: %d | $%d | %s\n", productId, quantity[productId], price[productId], name[productId]);
    }
}

void Purchase() {
    int input;
    clearTerminal();
    
    printf("You have bought!\n");
    for (int i = 0; i < 10; i++) {
        if (choices[i]) {
            int cost = choices[i] * price[i];
            
            printf("$%d | quantity: %d | %s\n", cost, choices[i], name[i]);
            
            quantity[i] = quantity[i] - choices[i];
            choices[i] = 0;
        }
    }

    userChoice = 0;
    isBasket = 0;

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

    if (!(input == 0 || input == 1)) {
        printf("**Invalid choice");
        sleep(2);
        return;
    }

    if (input == 0) {
        clearTerminal();
        exit(0);
    } else if (input == 1) {
        return;
    }
}

void showBasket() {
    int input;
    bool allZero = 0;
    
    clearTerminal();

    if (!isBasket) {
        
        printf("Your products:\n");
        for (int i = 0; i < 10; i++) {
            if (choices[i]) {
                int cost = choices[i] * price[i];
                
                allZero = true;
                overall += cost;
                printf("$%d | quantity: %d | %s\n", cost, choices[i], name[i]);
            }
        }
        
        if (!allZero) {
            clearTerminal();
            printf("The basket is empty");
            return;
        }
        
    
        printf("\nOverall: $%d\n", overall);
        
        printf("\n0 - Buy \n");
        printf("1 - Continue shopping\n");
        
        printf("\nChoice: ");
        scanf("%d", &input);
        while (getchar() != '\n');
        
        if (!(input == 0 || input == 1)) {
            printf("**Invalid choice");
            sleep(2);
            return;
        }
    }
    
    
    if (input == 0) {
        isBasket = 1;
        Purchase();
        return;
    } else if (input == 1) {
        userChoice = 0;
        return;
    }


}

void handleUserChoice(){
    int ID, amount;
    int finish;
    
    if (!userChoice) {

        clearTerminal();
        printf("----\nWelcome to the Grocery Store!\n----\n\n");
        printProducts();
    
        printf("\nEnter the details of the product that you want to buy... ");
    
        printf("\nID: ");
        int isValid = scanf("%d", &ID);
        while (getchar() != '\n');
    
        if (isValid != 1 || !(ID >= 0 && ID <= 9)) {
            printf("\n**Incorrect ID number.");
            sleep(2);
            return;
        }
    
        printf("Quantity: ");
        scanf("%d", &amount);
        while (getchar() != '\n');
    
        bool isAvailable = (quantity[ID] - amount) >= 0;
    
        if (!(amount >= 0 && amount <= 100)) {
            printf("\n**Invalid amount.");
            sleep(2);
            return;
        } else if (!isAvailable) {
            printf("**Sorry, only %d items are available.", quantity[ID]);
            sleep(2);
            return;
        }
    
        choices[ID] += amount;
    
        printf("\n0 - to proceed to the checkout.");
        printf("\n1 - to buy more products.\n");
        printf("\nChoice: ");
        scanf("\n%d", &finish);
        while (getchar() != '\n');

    }


    if (finish == 0) {
        userChoice = 1;
        showBasket();
        return;
    } else if (finish == 1) {
        return;
    }
}
