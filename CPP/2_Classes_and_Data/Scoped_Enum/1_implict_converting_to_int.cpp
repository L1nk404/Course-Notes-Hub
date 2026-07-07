// 1_implict_converting_to_int.cpp

// C++23: g++ -std=c++23 1_implict_converting_to_int.cpp

#include <iostream>
#include <utility> // for std::to_underlying() (C++23)

int main()
{
    enum class Color
    {
        red,
        blue,
    };

    Color color{Color::blue};

    // std::cout << color << std::endl; // won't work, because there's no
    // implicit conversion to int
    std::cout << static_cast<int>(color)
              << std::endl; // explicit conversion to int, will prin 1
    std::cout << std::to_underlying(color)
              << std::endl; // converto to underlying type, will print 1 (C++23)

    return 0;
}
