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
        printf("\nEnter the ID of the product that you want to restock - ");
        scanf("%d", &ID);
        while (getchar() != '\n');
        printf("\nEnter the quantity of the product - ");
        scanf("%d", &amount);
        while (getchar() != '\n');
        printf("\nEnter F to finish restocking, otherwise press enter - ");
        scanf("%c", &finish);
        while (getchar() != '\n');

        if (finish == 'F') {
            userRole = -1;
            break;
        }
    }
    
}
