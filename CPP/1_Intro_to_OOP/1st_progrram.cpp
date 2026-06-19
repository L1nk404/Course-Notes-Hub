#include <cstdlib> // For exit function
#include <iostream>

void main_menu()
{
    /*
    cout stands for "Console Out"
    std for standard library
    endl stands for "End of line"
    */

    // Menu =========

    // 1 help
    std::cout << "1: Print help" << std::endl;
    // 2 exchange stats
    std::cout << "2: Print exchange stats " << std::endl;
    // 3 make an offer
    std::cout << "3: Make and offer" << std::endl;
    // 4 make a bid
    std::cout << "4: Make a bid" << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet" << std::endl;
    // 6 continus
    std::cout << "6: Continue" << std::endl;
    // 0 exit
    std::cout << "0: Exit" << std::endl;

    std::cout << "===================" << std::endl;
    std::cout << "Type in 0-6" << std::endl;

    int userOption;
    /*
    >> is called extraction operator
    */
    std::cin >> userOption;
    std::cout << "You choose: " << userOption << std::endl;

    // if
    if (userOption == 0) // bad input
    {
        std::cout << "Invalid choice. Choose 0-6" << std::endl;

        exit(EXIT_SUCCESS);
    }

    // Switch
    switch (userOption)
    {
        case 1:
            std::cout << "You need Help!\n" << std::endl;
            break;
        case 2:
            std::cout << "Market looks good\n" << std::endl;
            break;
        case 3:
            std::cout << "Mark and offer - enter the amount\n" << std::endl;
            break;
        case 4:
            std::cout << "Make a bid - enter the amout\n" << std::endl;
            break;
        case 5:
            std::cout << "You wallet is empty!\n" << std::endl;
            break;
        case 6:
            std::cout << "Continuing\n" << std::endl;
            break;
        default:
            std::cout << "Invalid Option. Choose 1-6!\n" << std::endl;
            break;
    }
}

int main()
{
    while (true)
    {
        main_menu();
    }

    return 0;
}