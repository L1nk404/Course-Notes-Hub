#include <stdio.h>

int main()
{
    int price, totalPrice = 0;

    // Note that we have a repeated code on lines 9 and 14.
    /*
    printf("Please enter a price:");

    while (price != 0)
        {
            totalPrice = totalPrice = price;
            printf("PLeace enter a price: ");
            scanf("%d", &price);
        }
    */
    // To avoid that, we use a Do-While Loop.

    do
        {
            printf("PLeace enter a price: ");
            scanf("%d", &price);
            totalPrice = totalPrice + price;
        }
    while (price != 0); // Condition for loop

    printf("Total Order Price = %d \n", totalPrice);

    return 0;
}