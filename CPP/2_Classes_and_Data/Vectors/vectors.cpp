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

    // vector with std::list
    std::vector<std::string> vecOfStr(listOfStr.begin(), listOfStr.end());

    for (std::string str : vecOfStr)
        std::cout << str << std::endl;
}

void start_by_copying_from_another_vector()
{
    std::cout << "\n===============================" << std::endl;
    std::cout << "Start by copying from another vector:" << std::endl;
    std::vector<std::string> vecOfStr;
    vecOfStr.push_back("first");
    vecOfStr.push_back("sec");
    vecOfStr.push_back("third");
    // Vector with other string object
    std::vector<std::string> vecOfStr3(vecOfStr);
}

/*
When using certain initialization, you might need to set the size of the vector.
Size refers to the number of elements a vector contains. It is not the same as
capacity, which is the maximum number of elements a vector can contain.

To manage it, you can use size() function:
*/
void size_example()
{
    std::cout << "\n===============================" << std::endl;
    std::cout << "size() example:" << std::endl;

    std::vector<int> v{1, 2, 3, 4, 5};
    int n = v.size();

    std::cout << "Size of the vector is: " << n << std::endl;
}

/*
Most of the time, you will need to access a specified element in a C++ vector.
To do that, you can use the [] selector function as shown below:*/
void acessing_by_index()
{
    std::cout << "\n===============================" << std::endl;
    std::cout << "Acessing by Index:" << std::endl;
    std::vector<int> v{1, 2, 3, 4, 5};

    std::cout << "Index 0: " << v.operator[](0)
              << std::endl; // shorthand syntax
    std::cout << "Index 1: " << v[1]
              << std::endl; // the same call, written as an ordinary member
                            // function call
    std::cout << "Index 2: " << v.operator[](2) << std::endl;
    std::cout << "Index 1: " << v[3] << std::endl;
    std::cout << "Index 4: " << v.operator[](4) << std::endl;
}

int main()
{
    vector_with_default_value();
    start_with_an_array();
    start_with_a_list();
    start_by_copying_from_another_vector();
    size_example();
    acessing_by_index();

    return 0;
}
