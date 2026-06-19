// SmallString.cpp

#include <iostream>
#include <string>

/*
Makes standard library names available without the "std::" prefix.
For example, allows writing "string" instead of "std::string",
and "cout" instead of "std::cout".
*/
using namespace std;

int main()
{
    string imBlank;
    string heyMom("Where are my socks");
    string standardReply = "Beamed into deep"
                           "space on wide angle dispersion?";
    string useThisOneAgain(standardReply);

    cout << "- ImBlank:" << imBlank << endl;
    cout << "- heyMom: " << heyMom << endl;
    cout << "- standardReply: " << standardReply << endl;
    cout << "- useThisOneAgain: " << useThisOneAgain << endl;

    return 0;
}