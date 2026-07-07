// 1_scoped_enum_ex1

#include <iostream>

int main()
{
    /* Scope of the Color
    main()'s scope region
        └── Color (the enumeration) lives here
            └── Color's own scope region (created by "enum class")
                └── red, blue (the enumerators) live here
    */
    enum class Color //"enum class" defines this as a scoped enumeration rathand
                     // than an an unscoped enumeration
    {
        red, // red is considered part of Color's scope region
        blue,
    };

    enum class Fruit
    {
        banana, // bana is considered part of Fruit's scope region
    };

    Color color{Color::red}; // note: red is not directly accessible, we have to
                             // use Color::red
    Fruit fruit{Fruit::banana}; // same for banana

    if (color == fruit) // compile error: the compiler doesn't how to compare
                        // different types Color and Fruit
        std::cout << "color and fruit are equal\n" << std::endl;
    else
        std::cout << "color and fruit are not the equal\n" << std::endl;

    return 0;
}