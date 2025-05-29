/*================================================================================
Roll

In this code we'll use Pseudorandom number generator (PRNG)
https://en.wikipedia.org/wiki/Pseudorandom_number_generator

Specifically Linear congruential generator (LCG):
https://en.wikipedia.org/wiki/Linear_congruential_generator

The generator is defined by the recurrence relation:

X_{n+1} = (aX_n + c) mod(m)

Where:

m, 0 < m : Is the "Modulus" -> Range definer
a, 0 < a < m: Is the multiplier
c, 0 =< c < m - The increment
X_0, 0 =< X_0 < m - The "seed"

[>>] Generalized LCG to generate numbers less than 10^9



1. Choosing the modulus (m):
    - Since we want numbers less than 10^9, set m = 10^9.
    - This ensures the output range will be [0, 10^9 - 1].

2. Choosing the multiplier (a):
    - To achieve a full period, a must be chosen carefully.
    - A good rule when m is not a power of 2 is to select a prime number close
to √m.
    - Example: a = 48271 is a commonly used multiplier in many LCGs.
    - Alternatively, for large m, the multiplier can be chosen as large prime
numbers with good randomness properties.

3. Choosing the increment (c):
    - The increment c must be relatively prime to m (i.e., gcd(c, m) = 1).
    - A simple choice for c is an odd number that is not divisible by any of
m's prime factors.
    - Example: c = 12345 works well for m = 10^9 since gcd(12345, 10^9) = 1.

4. LCG Example:
    - Modulus (m) = 10^9
    - Multiplier (a) = 48271
    - Increment (c) = 12345

    The recurrence relation is:
    X_{n+1} = (a * X_n + c) % m

    This will generate random numbers between 0 and 999,999,999.
================================================================================*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// time.h used for test
#include <time.h>

int Euclidian_Alghorithm(int numerator, int denominator) // GCD
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

    while (denominator != 0)
        {
            R = numerator % denominator;
            numerator = denominator; // numerator receives previous R value
            denominator = R;
        }

    return numerator > 0 ? numerator : -numerator; // returning positive GCD
}

int prime_finder(int num)
{
    /*
    This funcion looks for a prime from M by checking divisibility by any number
    from [i,sqrt(M)].
    */

    int i;
    double seed_sqrt = ceil(sqrt(num));
    int int_seed_sqrt = seed_sqrt; // implicit type conversion.

    if (num < 0) // M input control
        {
            printf("<int num> must be greater than 0!\n");
            exit(1);
        }

    for (i = 2; i <= int_seed_sqrt; i++)
        {
            if (num % i == 0)
                {
                    // printf("%d is NOT prime\n", M); // debug
                    return prime_finder(num + 1);
                }
        }

    // printf("%d is prime\n", num); // debug
    return num;
}

// double right_RiemmannSum(double a, double b)
// {
//     if (a > b)
//         {
//             printf("B must be greater than A!\n");
//             exit(1);
//         }

//     int i;
//     double sum = 0;
//     double ds = (b - a) / pow(10, 6);

//     while (a <= b)
//         {
//             double function = (pow(sin(a), 2)) + pow(cos(a - 1), 2);

//             sum = sum + function * ds;
//             a = a + ds;
//         }

//     return sum;
// }

int rool(int seed, int m)
{
    int i;

    // int seed;
    int a, c;
    int GCD;
    int X;

    if (m <= 0)
        {
            printf("M must be greater than 0!\n");
            exit(0);
        }

    /* Choosing a */
    if (a > 0 && (int)sqrt(m) % 2) // Checking if sqrt(m) is power of 2
        {
            a = a % 8;
        }
    else
        {
            a = prime_finder((int)sqrt(m));
        }

    // printf("a: %d\n", a); // debug
    /* Choosing c */

    while (GCD != 1) // Looking for prime factors of m.
        {
            GCD = Euclidian_Alghorithm(m, i);
            i == prime_finder(i);
            i++;
        }

    c = i;
    // printf("c: %d\n", c); // debug

    /* LGC, let be X_n = seed*/
    X = (a * c * seed) % m;

    return X;
}

// int main()
// {
//     int seed = time(NULL);
//     int m = 100;
//     int i;
//     int X;

//     for (i = 1; i <= 10; i++)
//         {
//             X = rool(seed, m);
//             if (X < 0)
//                 {
//                     X = (-1) * X;
//                 }
//             printf("num: %d\n", X);
//             seed = seed + time(NULL);
//             printf("seed = %d\n\n", seed);
//         }
// }