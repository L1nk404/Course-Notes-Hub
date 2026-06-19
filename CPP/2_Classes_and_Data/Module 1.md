## Getting Ready for This Course:
package that will take you from the very fundamentals of C++, all the way to building a cryptocurrency exchange platform.
#####  List of readings for this course:
**The std::string data type. Summary of the various ways you can create std::string objects in C++.** 

- [https://www.tutorialspoint.com/cplusplus/cpp_strings.htm](https://www.tutorialspoint.com/cplusplus/cpp_strings.htm)

- [https://www.programiz.com/cpp-programming/strings](https://www.programiz.com/cpp-programming/strings)

- [https://www.linuxtopia.org/online_books/programming_books/c++_practical_programming/c++_practical_programming_057.html](https://www.linuxtopia.org/online_books/programming_books/c++_practical_programming/c++_practical_programming_057.html)

**The Enum class.**

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

Another slightly more subtle initialization technique involves the use of the string iterators `begin()` and `end()`. These member functions belong to the `string` class and return iterators that indicate the start and one-past-the-end position (>It points to the position immediately after the last element) of the character sequence stored in a string. Although they are sometimes referred to as `string::begin()` and `string::end()` to emphasize that they are members of the `string` class, they are not [[Glossary#^7a60d1|static member function]] and therefore must be called through a string object, such as `source.begin()` and `source.end()`. By passing these iterators to a string constructor, the constructor copies all characters in the range `[begin(), end())` into the new string. This technique treats a string like a [[Glossary#^8caaa9|container]] object (which you've seen primarily in the form of [[Glossary#^239e87|vector]] so far), which uses iterators to indicate the start and end of a sequence of characters. In this way you can hand a string constructor two iterators, and it copies from one to the other into the new string:

Another slightly more subtle initialization technique involve the os the **string iterators** `string::begin()` and `string::end()`.

