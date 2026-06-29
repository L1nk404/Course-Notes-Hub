// 0_flags.cpp

#include <iostream>

enum designFlags
{                 // Binary
    ITALICS = 1,  // 00000001
    BOLD = 2,     // 00000010
    UNDERLINE = 4 // 00000100
};

int main()
{
    int myDesign = BOLD | UNDERLINE;

    /*
    Since the Flags don't share any 1 bit, it can be merged to with the OR
    `|` operator (OR equivalent to Sum ( | == + ) in Boolean Algera)

      00000010
    | 00000100
    ___________
      00000110
    */

    std::cout << myDesign << std::endl;

    return 0;
}