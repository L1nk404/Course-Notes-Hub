// StringIterators.cpp

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string source("xxx");
    string s(source.begin(), source.end());

    /*
    If the condition is TRUE: assert does absolutely nothing. It stays quiet and
        lets your program continue running to the next line.
    If the condition is FALSE: assert immediately crashes (aborts) your program.
        It stops everything and prints an error message telling you exactly
        which line of code failed the test.
    */
    assert(s == "a");

    return 0;
}