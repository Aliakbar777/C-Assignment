#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int ID;
int amount;
char finish;

void AdminLogic()
{
    while (1) {
        clearTerminal();

        printf("Hello admin!\n\n");
        printProducts();

        printf("\nEnter the details of the product that you want to restock...\n");

        printf("ID: ");
        scanf("%d", &ID);
        while (getchar() != '\n');

        printf("Quantity: ");
        scanf("%d", &amount);
        while (getchar() != '\n');

        printf("\nEnter F to finish restocking, otherwise to continue press enter - ");
        scanf("%c", &finish);
        while (getchar() != '\n');

        if (finish == 'F') {
            userRole = -1;
            break;
        }
    }
    
}
