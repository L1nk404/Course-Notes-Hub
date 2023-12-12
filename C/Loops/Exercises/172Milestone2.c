/*
Do you prefer receive 1 milion USD right now or receive
0.01*2^t where t is a day for 1 to 30?
Write a program that says each is better.
*/

#include <stdio.h>

int main()
{
    int i;           // Controling the for
    int product = 1; // Used to power calc

    printf("Do you prefer receive 1,000,000 USD right now, or receive 0.01 USD "
           "that double for day for 30 days?\n\n");

    for (i = 1; i <= 30; i++)
        {
            product = product * 2;
        }

    printf("If you choose the second option, congratulations, you received "
           "%.2lf. That's %.2lf more than 1 million dolars.\n\n",
           ((double)product * 0.01), (((double)product * 0.01) - 1000000));

    return 0;
}