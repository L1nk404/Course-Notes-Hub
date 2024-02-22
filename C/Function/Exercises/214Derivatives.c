#include <math.h> // for math operations
#include <stdio.h>
#include <stdlib.h>

float derivative(float c, float x, float n)
{
    float powerValue = pow(x, n - 1);
    return n * c * powerValue;
}

int main()
{
    /*main code receiving user's input and calling derivative function*/
    return 0;
}