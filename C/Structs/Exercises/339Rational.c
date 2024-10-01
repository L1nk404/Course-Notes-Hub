/*
** Exercise - Rational Numbers **
 Design a rational number struc called Rational:

 - Provide Increment, decrement, addition, subtraction, multiplication,
division, smaller, bigger.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int numerator;
    int denominator;
} Rational;

int Euclidian_Alghorithm(int numerator, int denominator)
{
    /*
    https://math.libretexts.org/Courses/Monroe_Community_College/MTH_220_Discrete_Math/3%3A_Proof_Techniques/3.5%3A_The_Euclidean_Algorithm
    https://www.freecodecamp.org/news/euclidian-gcd-algorithm-greatest-common-divisor/
    Pseudo Code of the Algorithm-
    Step 1: Let a, b be the two numbers
    Step 2: a mod b = R
    Step 3: Let a = b and b = R
    Step 4: Repeat Steps 2 and 3 until a mod b is greater than 0
    Step 5: GCD = b
    Step 6: Finish
    */

    int R; // This will hold the remainder

    if (denominator == 0)
        {
            printf("Denominator cannot be zero!\n");
            return -1; // Error code for zero denominator
        }

    while (denominator != 0)
        {
            R = numerator % denominator;
            numerator = denominator; // numerator receives previous R value
            denominator = R;
        }

    return numerator > 0 ? numerator : -numerator; // returning positive GCD
}

void Frac_Reduction(Rational *frac)
{
    int original_numerator = frac->numerator;
    int original_denominator = frac->denominator;
    int GCD = Euclidian_Alghorithm(original_numerator, original_denominator);

    (*frac).numerator /= GCD;
    (*frac).denominator /= GCD;
}

void increment(Rational *number)
{
    (*number).numerator = (*number).numerator + (*number).denominator;
}

void decrement(Rational *number)
{
    (*number).numerator = (*number).numerator - (*number).denominator;
}

Rational Rational_Calc(Rational num1, Rational num2, char *op)
{
    Rational result;
    int num1_num = num1.numerator, num1_den = num1.denominator;
    int num2_num = num2.numerator, num2_den = num2.denominator;

    if (strcmp(op, "+") == 0) // if strings are equal, strcmp return 0
        {
            result.numerator = num1_num * num2_den + num2_num * num1_den;
            result.denominator = num1_den * num2_den;
        }
    else if (strcmp(op, "-") == 0)
        {
            result.numerator = num1_num * num2_den - num2_num * num1_den;
            result.denominator = num1_den * num2_den;
        }
    else if (strcmp(op, "*") == 0)
        {
            result.numerator = num1_num * num2_num;
            result.denominator = num1_den * num2_den;
        }
    else if (strcmp(op, "/") == 0)
        {
            if (num2_num == 0)
                {
                    printf("Numerator of number 2 cannot be 0!\n\n");
                    exit(1);
                }
            result.numerator = num1_num * num2_den;
            result.denominator = num1_den * num2_num;
        }

    Frac_Reduction(&result);

    return result;
}

Rational inputNumber()
{
    Rational num;

    printf("Enter num1 enumerator: ");
    scanf("%d", &num.numerator);
    printf("Enter num1 denominator: ");
    scanf("%d", &num.denominator);

    return num;
}

void printRational(Rational number)
{
    if (number.denominator == 1)
        printf("%d\n", number.numerator);
    else
        printf("%d/%d\n", number.numerator, number.denominator);
}

int main()
{
    Rational num1 = inputNumber();
    Rational num2 = inputNumber();

    system("clear");

    // Increment
    printf("The increment of %d/%d is: ", num1.numerator, num1.denominator);
    increment(&num1);
    printRational(num1);

    // Decrement
    printf("The decrement of %d/%d is: ", num1.numerator, num1.denominator);
    decrement(&num1);
    printRational(num1);

    // Sum
    printf("The sum of %d/%d with %d/%d is: ", num1.numerator, num1.denominator,
           num2.numerator, num2.denominator);
    printRational(Rational_Calc(num1, num2, "+"));

    // Subtraction
    printf("The subtraction of %d/%d with %d/%d is: ", num1.numerator,
           num1.denominator, num2.numerator, num2.denominator);
    printRational(Rational_Calc(num1, num2, "-"));

    // Multiplication
    printf("The Multiplication of %d/%d with %d/%d is: ", num1.numerator,
           num1.denominator, num2.numerator, num2.denominator);
    printRational(Rational_Calc(num1, num2, "*"));

    // Division
    printf("The Division of %d/%d with %d/%d is: ", num1.numerator,
           num1.denominator, num2.numerator, num2.denominator);
    printRational(Rational_Calc(num1, num2, "/"));
    return 0;
}
