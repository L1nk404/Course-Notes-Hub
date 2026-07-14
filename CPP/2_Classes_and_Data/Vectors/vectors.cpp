#include <iostream>
#include <list>
#include <string>
#include <vector>

void vector_with_default_value()
{
    std::cout << "\n===============================" << std::endl;
    std::cout << "Vector starts with default value:" << std::endl;

    // Vector with 5 integers
    // Default value of integers will be 0.
    std::vector<int> vecOfInts(5);

    for (int x : vecOfInts)
        std::cout << x << std::endl;
}

void start_with_an_array()
{
    std::cout << "\n===============================" << std::endl;
    std::cout << "Start with an array:" << std::endl;

    // Array of string objects
    std::string arr[] = {"first", "sec", "third", "fourth"};

    // Vector with a string array
    std::vector<std::string> vecOfStr(arr,
                                      arr + sizeof(arr) / sizeof(std::string));

    for (std::string str : vecOfStr)
        std::cout << str << std::endl;
    std::cout << (arr, arr + sizeof(arr) / sizeof(std::string)) << std::endl;
}

void start_with_a_list()
{
    std::cout << "\n===============================" << std::endl;
    std::cout << "Start with a list:" << std::endl;

    // std::list of 5 strings objects
    std::list<std::string> listOfStr;
    listOfStr.push_back("first");
    listOfStr.push_back("sec");
    listOfStr.push_back("third");
    listOfStr.push_back("fouth");

    // vector with std::liost
    std::vector<std::string> vecOfStr(listOfStr.begin(), listOfStr.end());

    for (std::string str : vecOfStr)
        std::cout << str << std::endl;
}

int main()
{
    vector_with_default_value();
    start_with_an_array();
    start_with_a_list();

    return 0;
}