#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "../../utilities/utils.h"
#include "productLogic.h"

#define PRODUCT_COUNT 10
#define NAME_LEN 9

char name[PRODUCT_COUNT][NAME_LEN] = {
    "Carrot", "Apple", "Potato", "Cucumber", "Flour",
    "Bread", "Beef", "Sausage", "Rice", "Ketchup",
};
int price[PRODUCT_COUNT] = {2, 2, 1, 3, 4, 3, 7, 6, 4, 5};
int quantity[PRODUCT_COUNT] = {20, 30, 30, 30, 20, 20, 15, 30, 20, 40};

void printProducts()
{
    int productId;
    
    printf("Groceries:\n");
    for (productId = 0; productId < 10; productId++)
    {
        printf("ID: %d | Available: %d | $%d | %s\n", 
            productId, quantity[productId], price[productId], name[productId]);
    }
}
