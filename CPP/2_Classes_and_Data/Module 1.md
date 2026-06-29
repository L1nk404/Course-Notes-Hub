## Getting Ready for This Course:
package that will take you from the very fundamentals of C++, all the way to building a cryptocurrency exchange platform.
#####  List of readings for this course:
**The std::string data type. Summary of the various ways you can create std::string objects in C++.** 

- [https://www.tutorialspoint.com/cplusplus/cpp_strings.htm](https://www.tutorialspoint.com/cplusplus/cpp_strings.htm)

- [https://www.programiz.com/cpp-programming/strings](https://www.programiz.com/cpp-programming/strings)

- [https://www.linuxtopia.org/online_books/programming_books/c++_practical_programming/c++_practical_programming_057.html](https://www.linuxtopia.org/online_books/programming_books/c++_practical_programming/c++_practical_programming_057.html)

**C++ Enumerations**

- [https://www.learncpp.com/cpp-tutorial/enum-classes/](https://www.learncpp.com/cpp-tutorial/enum-classes/)

- [https://en.cppreference.com/w/cpp/language/enum](https://en.cppreference.com/w/cpp/language/enum)

- [https://www.programiz.com/cpp-programming/enumeration](https://www.programiz.com/cpp-programming/enumeration)

**The std::vector. Note the difference between initialising with curly braces and normal braces.**

- [https://www.cplusplus.com/reference/vector/vector/vector/](https://www.cplusplus.com/reference/vector/vector/vector/)

- [https://www.bitdegree.org/learn/c-plus-plus-vector](https://www.bitdegree.org/learn/c-plus-plus-vector)

The syntax for a class. Information about how to add function members to classes. Do not worry too much about that for now, we will get into that later!

---
## C++ Strings
#### Creating and Initializing C++ strings
Creating and initializing strings is a straightforward proposition and fairly flexible. 

```cpp
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
```

```bash
==== OUTUPUT ====
❯ g++ 2_SmallString.cpp && ./a.out && rm a.out
- ImBlank:
- heyMom: Where are my socks
- standardReply: Beamed into deepspace on wide angle dispersion?
- useThisOneAgain: Beamed into deepspace on wide angle dispersion?
```

In the `SmallString.cpp` example above, the first string, `ImBlank`, is declared but contains no  initial value. Unlike C char array, which would contain a random and meaningless bit pattern until initialization, `imBlank` does contain meaningful information. This string is initialized to hold no characters and can properly report its zero length and absence of data elements using class members functions.
The next string, `heyMom`, is initialized by the literal argument "Where are my socks?" This form of initialization uses a quoted character array as a parameter to the **string** [[Glossary#^3fa7f6|constructor]]. By contrast, `standardReply` is simply initialized with an [[Glossary#^2774e3|assignment operator]]. The last string of the group, `useThisOneAgain`, is initialized using an existing C++ **string** object. Put another way, this example illustrates that **string** objects let you do the following:
 - Create an empty **string** and defer initializing it with character data.
- Initialize a **string** by passing a literal, quoted character array as an argument to the constructor.
- Initialize a **string** using the equal sign (**=**).
- Use one **string** to initialize another.

These are the simplest forms of **string** initialization, but variations offer more flexibility and control. You can do the following:
- Use a portion of either a C **char** array or a C++ **string**.
- Combine different sources of initialization data using **operator+**.
- Use the **string** object s **substr( )** member function to create a substring.

Here s a program that illustrates these features:

```cpp
// SmallString2.cpp

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1("What is the sound of one clam napping?");
    string s2("Anything worth doing is worth overdoing.");
    string s3("I saw Elvis in a UFO");
    cout << "- s1: " << s1 << endl;
    cout << "- s2: " << s2 << endl;
    cout << "- s3: " << s3 << endl;

    // Copy the first 8 chars:
    string s4(s1, 0, 8);
    cout << "- Copy the first 8 chars of s1: " << s4 << endl;

    // Copy 6 chars form the middle of the s2:
    string s5(s2, 15, 6);
    cout << "- Copy 6 chars form the middle of the s2: " << s5 << endl;

    // Copy from middle to end:
    string s6(s3, 6, 15);
    cout << "- Copy s6 from middle to end: " << s6 << endl;
    // Copy many different things:
    string quoteMe = s4 + "that" +
                     // substr() copies 10 chars from index 20
                     s1.substr(20, 10) + s5 +
                     // substr() copies up to either 100 char
                     // or eos(End of String) starting at element 5
                     "with" + s3.substr(5, 100) +
                     // OK to copy a single char this way
                     s1.substr(37, 1);
    cout << "- quoteMe: " << quoteMe << endl;

    string copyMe = quoteMe.substr();
    cout << "- copyMe: " << copyMe << endl;

    return 0;
}
```

```bash
==== OUTUPUT ====
❯ g++ 2_SmallString2.cpp && ./a.out && rm a.out
- s1: What is the sound of one clam napping?
- s2: Anything worth doing is worth overdoing.
- s3: I saw Elvis in a UFO
- Copy the first 8 chars of s1: What is 
- Copy 6 chars form the middle of the s2: doing 
- Copy s6 from middle to end: Elvis in a UFO
- quoteMe: What is that one clam doing with Elvis in a UFO?
- copyMe: What is that one clam doing with Elvis in a UFO?
```

The **string** member function `substr(i, j)` takes a starting position as its first argument ($i$) and the number and the number of characters to select as the second argument ($j$). Both arguments have default values. If you say `substr()` with an empty argument list, you produce a copy of the entire **string**, so this is convenient to duplicate a string.

Another slightly more subtle initialization technique involves the use of the string iterators `begin()` and `end()`. These member functions belong to the `string` class and return iterators that indicate the start and one-past-the-end position (it points to the position immediately after the last element) of the character sequence stored in a string. Although they are sometimes referred to as `string::begin()` and `string::end()` to emphasize that they are members of the `string` class, they are not [[Glossary#^7a60d1|static member function]] and therefore must be called through a string object, such as `source.begin()` and `source.end()`. By passing these iterators to a string [[Glossary#^6978c5|constructor]], the constructor copies all characters in the range `[begin(), end())` into the new string. This technique treats a string like a [[Glossary#^8caaa9|container]] object (which you've seen primarily in the form of [[Glossary#^239e87|vector]] so far), which uses iterators to indicate the start and end of a sequence of characters. In this way you can hand a string constructor two iterators, and it copies from one to the other into the new string:

Another slightly more subtle initialization technique involve the os the **string iterators** `string::begin()` and `string::end()`.

```cpp
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

    In others words, if the program runs after this line it means that s == source
    */
    assert(s == source);

    return 0;
}
```

The iterators are not restricted to `begin()` and `end()`; you can increment, decrement, and add integer offsets to them, allowing you to extract a subset of characters from the source string.

C++ strings may not be initialized with single characters or with ASCII or other integer values. You can initialize a string with a number of copies of a single character, however:

```cpp
//: C03:UhOh.cpp

#include <cassert>
#include <string>
using namespace std;

int main()
{
    // Error: no single char inits
    string nothingDoing1('a');
    // Error: no integer inits
    string nothingDoing2(0x37);
    // The following is legal:
    string okay(5, 'a');
    assert(okay == string("aaaaa"));

    return 0;
}
```

The first argument indicates the number of copies of the second argument to place in the string. The second argument can only be a single **char**, not a **char** array.
## C++ Enumeration
An **enumeration** is a user-defined data type that consists of integral constants. To define an enumeration, [keyword](https://www.programiz.com/cpp-programming/keywords-identifiers) **enum** is used.

```cpp
enum season { spring, summer, autumn, winter };
```

Here the name of the enumeration is `season`.
And, `spring`, `summer`, `autumn` and `winter` are values of type `season`.
By default, `spring = 0`, `summer = 1` and so on. You can change the value of an enum element during declarion:

```cpp
enum season 
{   spring = 0, 
    summer = 4, 
    autumn = 8,
    winter = 12
};
```

#### Enumerated Type Declaration
When you create an enumerated type, only a blueprint for the variable is created. Here's how you can create variables of **enum** type:

```cpp
enum boolean { false, true };

// inside function
enum boolean check;
```

Here, a variable check of type `enum boolean` is created.
Here is another way to declare the same check variable using different syntax.

```cpp
enum boolean 
{ 
   false, true
} check;
```

#### Why are enums used in C++ programming?
An enum variable takes only one value out of many possible values. Let us take an example:

```cpp
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
```

```bash
==== OUTUPUT ====
❯ g++ 0_enum_example.cpp && ./a.out && rm ./a.out
Size of enum variable: 4 bytes.
```

It's because the size of an integer is 4 bytes. This makes enum a good choice to work with flags.
You can accomplish the same task using [C++ structures](https://www.programiz.com/cpp-programming/structure). However, working with enums gives you efficiency along with flexibility.
Supose you are designing a button for a Window application. You can set flags `ITALICS`, `BOLD` and `UNDERLINE` to wortk with text:

``` cpp
enum designFlags
{                 // Binary
    ITALICS = 1,  // 00000001
    BOLD = 2,     // 00000010
    UNDERLINE = 4 // 00000100
};
```
Note that there's a reason  why all the integral constants are power of 2 in the above pseudocode.
Since, the integral constants are power of 2, you can combine two or more flags at once without overlaping using bitwise OR | operator. 

> [!NOTE] 
> The OR  `|` operator in Boolean algebra is the equivalent of the sum `+` operator

Let's look to the example:
```cpp
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
```

```bash
==== OUTUPUT ====
❯ ../../compile_n_run.sh 0_flags.cpp
6
``` 

When the output is **6**, you always know that `BOLD` and `UNDERLINE` are used.
Also, you can add flags to your requirements.
You can accomplish almost anything in C++ programming without using enumerations. However, they can be pretty handy in certain situations. That's what differentiates good programmers from great programmers.
### 1. Scoped enumerations (enum classes)
Although unscoped enumerations are distinct types in C++, they are not [[Glossary#^4b7b35|type safe]], and in some cases will allow you to do things that don't make sense. Consider the following case:

```cpp
// 1_fruits_n_colors_are_equals.cpp

#include <iostream>

int main()
{
    enum Color
    {
        red,
        blue
    };

    enum Fruit
    {
        banana,
        apple
    };

    Color color{red};
    Fruit fruit{banana};

    if (color == fruit) // The compiler will compare color and fruit as integer
        std::cout << "\n[>>] color and fruit are equal!\n" << std::endl;
    else
        std::cout << "\n[>>] color and fruit are not equal!\n" << std::endl;

    return 0;
}
```

```bash
==== OUTUPUT ====
❯ g++ fruits_n_colors_are_equals.cpp && ./a.out && rm ./a.out
fruits_n_colors_are_equals.cpp: In function ‘int main()’:
fruits_n_colors_are_equals.cpp:22:15: warning: comparison between ‘enum main()::Color’ and ‘enum main()::Fruit’ [-Wenum-compare]
   22 |     if (color == fruit) // The compiler will compare color and fruit as integer
      |         ~~~~~~^~~~~~~~

[>>] color and fruit are equal!
```

When `color` and `fruit` are compared, the compiler will look to see if it knows how to compare a `Color` and/or `Fruit` to integers to see if it can find a match. Eventually the compiler will determine that if it converts both to integers, it can do the comparison. Since `color`and `fruit`are both set to enumerators that convert to integer value `0`, `color == fruit` is true.
