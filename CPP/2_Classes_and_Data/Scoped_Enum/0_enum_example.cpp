// 0_enum_example.cpp

#include <iostream>

enum suit
{
    club = 0,
    diamond = 10,
    hearts = 20,
    spades = 3,
} card;

int main()
{
    card = club;
    std::cout << "Size of enum variable: " << sizeof(card) << " bytes."
              << std::endl;

    return 0;
}