// fruits_n_colors_are_equals.cpp

#include <iostream>

int main()
{
    enum Color
    {
        red,
        blue
    };

    enum Fruit
    {
        banana,
        apple
    };

    Color color{red};
    Fruit fruit{banana};

    if (color == fruit) // The compiler will compare color and fruit as integer
        std::cout << "\n[>>] color and fruit are equal!\n" << std::endl;
    else
        std::cout << "\n[>>] color and fruit are not equal!\n" << std::endl;

    return 0;
}