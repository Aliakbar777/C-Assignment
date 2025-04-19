#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

char name[10][9];
int price[] = {2, 2, 1, 3, 4, 3, 7, 6, 4, 5};
int quantity[] = {20, 30, 30, 30, 20, 20, 15, 30, 20, 40};

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


void Basket(){
    int list[10][2];
    int ID;
    int amount;
    char finish;

    while (1) {
        clearTerminal();
        printf("----\nWelcome to the Grocery Store!\n----\n\n");
        printProducts();

        printf("\nEnter the ID of the product that you want to buy - ");
        scanf("%d", &ID);
        while (getchar() != '\n');

        printf("\nEnter the quantity - ");
        scanf("%d", &amount);
        while (getchar() != '\n');

        printf("\nEnter F to proceed to the checkout or press enter to buy more - ");
        scanf("%c", &finish);
        while (getchar() != '\n');

        if (finish == 'F') {
            userRole = -1; // Если что здесь не должно быть этой логики. Это чтобы проверить работает ли этот condiiton.
            sleep(1);
            break;
        }
    }
}