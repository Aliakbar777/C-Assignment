#ifndef PRODUCT_LOGIC_H
#define PRODUCT_LOGIC_H

#define PRODUCT_COUNT 10
#define NAME_LEN 9

extern char name[PRODUCT_COUNT][NAME_LEN];
extern int price[PRODUCT_COUNT];
extern int quantity[PRODUCT_COUNT];

void printProducts();

#endif