/*
    Develop a calculator that:
    1. Reads 1 character (+, - , * , /, %).
    2. Reads 2 numbers from user.
    3. Use Switch Cases to calculate and
    print out the result.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    double num1, num2;
    int module;
    char operator;

    printf("Enter a number: ");
    scanf("%lf", &num1);
    printf("Choose the operator [+ - * /]: "); // '%%' for print '%'
    scanf(" %c", &operator); // It's a good pratice to put a space before %c to
                             // consumming white spaces on input generated by
                             // break line or otherthings.
    printf("Enter another number: ");
    scanf("%lf", &num2);
    printf("\nThe result is: ");

    switch (operator) {
        case '+':
            printf("%.2lf\n", num1 + num2);
            break;
        case '-':
            printf("%.2lf\n", num1 - num2);
            break;
        case '*':
            printf("%.2lf\n", num1 * num2);
            break;
        case '/':
            if (num2 == 0)
                printf("You cannot divide by 0! \n");
            else
                printf("%.2lf\n", num1 / num2);
            break;
        case '%':
            if (num2 == 0)
                printf("You cannot divide by 0! \n");
            else {
                module = (int)num1 % (int)num2; // op requires int
                printf("%d", module);
            }
            break;
        default:
            printf("FAILED.. Try again!\n");
    }

    return 0;
}