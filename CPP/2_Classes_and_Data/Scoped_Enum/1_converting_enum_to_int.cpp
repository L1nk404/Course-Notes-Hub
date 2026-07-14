// 1_converting_enum_to_int.cpp

#include <iostream>
#include <type_traits>

enum class Animals
{
    chicken,  // 0
    dog,      // 1
    cat,      // 2
    elephant, // 3
    duck,     // 4
    snake,    // 5

    maxAnimals,
};

/*
Overload the unary + operator to convert an enum to the underlying type
adapted from https://stackoverflow.com/a/42198760, thanks to Pixelchemist for
the idea In C++23, you can #include <utility> and return std::to_underlying(a)
instead
*/
template <typename T> constexpr auto operator+(T a) noexcept
{
    return static_cast<std::underlying_type_t<T>>(a);
}

int main()
{
    std::cout << +Animals::elephant << '\n'; // convert Animals::elephant to an
                                             // integer using unary operator+

    return 0;
}
