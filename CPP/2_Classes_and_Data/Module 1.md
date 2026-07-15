## Índice
- [[#Getting Ready for This Course:]]
	- [[#List of readings for this course:]]
- [[#C++ Strings]]
	- [[#Creating and Initializing C++ strings]]
- [[#C++ Enumeration]]
		  - [[#Enumeration vs Enumerator]]
		  - [[#Enumerated Type Declaration]]
		  - [[#Why are enums used in C++ programming?]]
	- [[#1. Scoped enumerations (enum classes)]]
		- [[#Scoped enumerations]]
		- [[#Scoped enumerations define their own scope regions]]
		- [[#Scoped enumerations don't implicitly convert to integers]]
		- [[#Converting a Scoped Enum to Its Underlying Type via `operator+`]]
		- [[#`using enum` statements]]
- [[#Vector]]
	- [[#Why Use Vectors in C++]]
	- [[#How to Create C++ Vectors]]
		- [[#Iterators]]
		- [[#Modifiers]]
	- [[#Constructing a `std vector` from a Raw Array (Range Constructor)]]
		- [[#Why Two Pointers Instead of a Count?]]
		- [[#Constructor Comparison]]
		- [[#A Bug Worth Noting in the Original Snippet]]
	- [[#Vector Examples]]
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

**The syntax for a class. Information about how to add function members to classes. Do not worry too much about that for now, we will get into that later!**
- [https://www.tutorialspoint.com/cplusplus/cpp_classes_objects.htm](https://www.tutorialspoint.com/cplusplus/cpp_classes_objects.htm)
- [https://en.cppreference.com/w/cpp/language/class](https://en.cppreference.com/w/cpp/language/class)

**Information about constructors, including an explanation of why we were able to use the class even before we had written a constructor (i.e.because the compiler provides a default constructor).**
- [https://en.cppreference.com/w/cpp/language/default_constructor](https://en.cppreference.com/w/cpp/language/default_constructor)
- [https://www.learncpp.com/cpp-tutorial/constructors/](https://www.learncpp.com/cpp-tutorial/constructors/)
- [https://www.w3schools.com/cpp/cpp_constructors.asp](https://www.w3schools.com/cpp/cpp_constructors.asp)
- [https://www.geeksforgeeks.org/constructors-c/](https://www.geeksforgeeks.org/constructors-c/)

**Member initialiser lists.**
- [https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/#:~:text=Initializer%20List%20is%20used%20in,and%20y%20of%20Point%20class](https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/#:~:text=Initializer%20List%20is%20used%20in,and%20y%20of%20Point%20class) .
- [https://en.cppreference.com/w/cpp/language/constructor](https://en.cppreference.com/w/cpp/language/constructor)
- [https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/](https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/)

**Examples and further explanation about using references and range loops.**
- [https://www.nextptr.com/tutorial/ta1208652092/how-cplusplus-rangebased-for-loop-works](https://www.nextptr.com/tutorial/ta1208652092/how-cplusplus-rangebased-for-loop-works)
- [https://www.geeksforgeeks.org/range-based-loop-c/](https://www.geeksforgeeks.org/range-based-loop-c/)
- [https://www.tutorialspoint.com/cplusplus/cpp_classes_objects.htm](https://www.tutorialspoint.com/cplusplus/cpp_classes_objects.htm)
- [https://en.cppreference.com/w/cpp/language/class](https://en.cppreference.com/w/cpp/language/class)

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

---
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

#### Enumeration vs Enumerator
Before continue, let's explain the difference between **Enumeration** and **Enumerator**.
Let's use the following example:

```cpp
enum class Color   // Color is the enumeration (the type)
{
    red,           // red is an enumerator (a value of that type)
    blue,          // blue is an enumerator (a value of that type)
};
```

So:
- **Enumeration** - Is the type itself. Like in the example above, the `Color`.
- **Enumerator** - Are the individual named values inside the enumeration. In the example, `red`and `blue`.
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
### Scoped enumerations (enum classes)
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
This doesn’t make sense semantically since `color` and `fruit` are from different enumerations and are not intended to be comparable. With standard enumerators, there’s no easy way to prevent this.
Because of such challenges, as well as the [[Glossary#^977f5f|namespace]] pollution problem (unscoped enumerations defined in the global scope put their enumerators in the global namespace), the C++ designers determined that a cleaner solution for enumerations would be of use.
#### Scoped enumerations
That solution is the **scoped enumeration** (often called an **enum class** in C++ for reasons that will become obvious shortly).
Scoped enumeration work in similarly to unscoped enumerations, but have two primary differences:
1. They won't implicitly convert to integers,
2. The enumerator are only placed into the scope region of the enumeration (not into the scope region where the enumeration is defined).

So, there are actually **two levels of nesting**:
```
main()'s scope region
 └── Color (the enumeration) lives here
      └── Color's own scope region (created by "enum class")
           └── red, blue (the enumerators) live here
```


To make a scoped enumeration, we use the keywords `enum class`. The rest of the scoped enumeration definition is the same as an unscoped enumeration definition. Here’s an example:

```cpp
// 1_scoped_enum_ex1

#include <iostream>

int main()
{
    enum class Color //"enum class" defines this as a scoped enumeration rathand
                     // than an an unscoped enumeration
    {
        red, // red is considered part of Color's scope region
        blue,
    };

    enum class Fruit
    {
        banana, // bana is considered part of Fruit's scope region
    };

    Color color{Color::red}; // note: red is not directly accessible, we have to
                             // use Color::red
    Fruit fruit{Fruit::banana}; // same for banana

    if (color == fruit) // compile error: the compiler doesn't how to compare
                        // different types Color and Fruit
        std::cout << "color and fruit are equal\n" << std::endl;
    else
        std::cout << "color and fruit are not the equal\n" << std::endl;

    return 0;
}
```

This program produces a compile error on line 23, since the scoped enumeration won’t convert to any type that can be compared with another type.


> [!NOTE] As an aside…
> The `class` keyword (along with the `static` keyword), is one of the most overloaded keywords in the C++ language, and can have different meanings depending on context. Although scoped enumerations use the `class` keyword, they aren’t considered to be a “class type” (which is reserved for structs, classes, and unions).
> `enum struct` also works in this context, and behaves identically to `enum class`. However, use of `enum struct` is non-idiomatic, so avoid its use.

#### Scoped enumerations define their own scope regions
Unlike unscoped enumerations, which place their enumerators in the same scope as the enumeration itself, scoped enumerations place their enumerators only in the scope region of the enumeration. In  the other words, scoped enumerations act like a namespace for their enumerators. This built-in namespacing helps reduce global namespace pollution and the potencial for name conflicts when scoped enumerations are used in the global scope.
To access a scoped enumerator, we do so just as if it was in a namespace having the same name as the scoped enumeration:

```cpp
#include <iostream>

int main()
{
    enum class Color // "enum class" defines this as a scoped enum rather than an unscoped enum
    {
        red, // red is considered part of Color's scope region
        blue,
    };

    std::cout << red << '\n';        // compile error: red not defined in this scope region
    std::cout << Color::red << '\n'; // compile error: std::cout doesn't know how to print this (will not implicitly convert to int)

    Color color { Color::blue }; // okay

    return 0;
}
```

Because scoped enumerations offer their own implicit namespacing for enumerators, there’s no need to put scoped enumerations inside another scope region (such as a namespace), unless there’s some other compelling reason to do so, as it would be redundant.
#### Scoped enumerations don’t implicitly convert to integers
Unlike non-scoped enumerators, scoped enumerators won’t implicitly convert to integers. In most cases, this is a good thing because it rarely makes sense to do so, and it helps prevent semantic errors, such as comparing enumerators from different enumerations, or expressions such as `red + 5`.

> [!NOTE] 
> Note that you can still compare enumerators from within the same scoped enumeration (since they are of the same type):

There are occasionally cases where it is useful to be able to treat a scoped enumerator as an integral value. In these cases, you can explicitly convert a scoped enumerator to an integer by using a `static_cast`. A better choice in C++23 is to use `std::to_underlying()` (defined in the \<utility\> header), which converts an enumerator to a value of the underlying type of the enumeration.

```cpp
// 1_implict_converting_to_int.cpp
// C++23: g++ -std=c++23 1_implict_converting_to_int.cpp

#include <iostream>
#include <utility> // for std::to_underlying() (C++23)

int main()
{
    enum class Color
    {
        red,
        blue,
    };

    Color color{Color::blue};

    // std::cout << color << std::endl; // won't work, because there's no
    // implicit conversion to int
    std::cout << static_cast<int>(color)
              << std::endl; // explicit conversion to int, will prin 1
    std::cout << std::to_underlying(color)
              << std::endl; // converto to underlying type, will print 1 (C++23)

    return 0;
}
```

Conversely, you can also `static_cast` an integer to a scoped enumerator, which can be useful when doing input from users:

#### Converting a Scoped Enum to Its Underlying Type via `operator+`
##### The Problem
Scoped enums (`enum class`) do **not** implicitly convert to integers. This is intentional — it's one of the two defining features of scoped enums (the other being built-in namespacing of enumerators).

```cpp
std::cout << Animals::elephant; // ERROR: no implicit conversion
```

The standard fix is `static_cast`:

```cpp
std::cout << static_cast<int>(Animals::elephant); // works, but verbose
```

The code below creates a **shortcut** for this: writing `+Animals::elephant` instead of `static_cast<int>(Animals::elephant)`.
##### The Full Code

```cpp
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
the idea. In C++23, you can #include <utility> and return std::to_underlying(a)
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
```

#### Breaking It Down

###### 1. Operator overloading — what does `operator+` mean?
Operators like `+`, `-`, `==` are actually special functions in disguise. C++ lets you define your **own** behavior for them for your own types. The syntax `operator+` literally means: _"I am defining what `+` does."_

Normally `+` is **binary** (takes two operands: `a + b`). Here it's written with **one** parameter:

```cpp
constexpr auto operator+(T a) noexcept
```

One parameter = this defines the **unary** `+` (the `+` that appears _before_ a single value, like `+5`, as opposed to `a + b`). Unary `+` normally does almost nothing useful for numbers (`+5` is just `5`) — which is exactly why it's a good candidate to repurpose: it's rarely used, so "hijacking" it for enums doesn't create confusing conflicts elsewhere.

> Whenever someone writes `+someValue`, and `someValue`'s type matches `T`, the compiler runs this function instead of the default (no-op) behavior.
###### 2. The template — why `template <typename T>`?
```cpp
template <typename T> constexpr auto operator+(T a) noexcept
```

`template <typename T>` means this function works for **any type** `T` — it isn't hardcoded to `Animals`. This makes the trick reusable for _any_ enum, not just this one. When the compiler sees `+Animals::elephant`, it deduces `T = Animals` automatically and generates a version of the function for that type.

> Think of `T` as a placeholder meaning "whatever type is actually used when this is called."
###### 3. The body — `std::underlying_type_t<T>`

```cpp
return static_cast<std::underlying_type_t<T>>(a);
```

Every scoped enum has an **underlying type** — the actual integer type used to store its values behind the scenes (`int` by default, unless specified otherwise). `std::underlying_type_t<T>` (from `<type_traits>`) asks the compiler: _"whatever `T` is, tell me its underlying integer type."_

For `Animals`, `std::underlying_type_t<Animals>` resolves to `int`, so the line effectively becomes:

```cpp
return static_cast<int>(a);
```

**Why not just hardcode `int`?** Because the function is generic — it needs to work correctly even for some _other_ enum whose underlying type is `long` or `char` instead of `int`. `std::underlying_type_t<T>` figures that out automatically for whatever enum is passed in.
###### 4. `constexpr` and `noexcept` (minor details)
- `constexpr` — allows the function to be evaluated at compile-time if possible (a performance/optimization detail).
- `noexcept` — a promise that this function will never throw an exception.

Neither changes _what_ the function does — just guarantees about _how_ it does it. Safe to set aside for now.
##### Putting It Together

```cpp
std::cout << +Animals::elephant << '\n';
```

1. `+Animals::elephant` triggers the overloaded `operator+`.
2. `T` is deduced as `Animals`.
3. The function casts `Animals::elephant` to its underlying type (`int`).
4. Result: `3` is printed — identical to `static_cast<int>(Animals::elephant)`, just shorter.
##### Takeaway
This is an advanced idiom combining:

- **Operator overloading** (unary `+`)
- **Templates** (generic over any enum type)
- **Type traits** (`std::underlying_type_t`)

These topics are usually taught _after_ enums, so treat this as a "cool pattern that exists" rather than something to fully derive from scratch right now. Revisit this snippet once templates and type traits are covered in depth.

> **C++23 note:** `std::to_underlying(a)` (from `<utility>`) does the same job natively, making this manual `operator+` trick unnecessary in newer code.

### `using enum` statements
Introduced in C++20, a `using enum` statement imports all of the enumerators from an enum into the current scope. When used with an enum class type, this allows us to access the enum class enumerators without having to prefix each with the name of the enum class.
This can be useful in cases where we would otherwise have many identical, repeated prefixes, such as within a switch statement:

```cpp
#include <iostream>
#include <string_view>

enum class Color
{
    black,
    red,
    blue,
};

constexpr std::string_view getColor(Color color)
{
    using enum Color; // bring all Color enumerators into current scope (C++20)
    // We can now access the enumerators of Color without using a Color:: prefix

    switch (color)
    {
    case black: return "black"; // note: black instead of Color::black
    case red:   return "red";
    case blue:  return "blue";
    default:    return "???";
    }
}

int main()
{
    Color shirt{ Color::blue };

    std::cout << "Your shirt is " << getColor(shirt) << '\n';

    return 0;
}
```

In the above example, `Color` is an enum class, so we normally would access the enumerators using a fully qualified name (e.g. `Color::blue`). However, within function `getColor()`, we’ve added the statement `using enum Color;`, which allows us to access those enumerators without the `Color::` prefix.

This saves us from having multiple, redundant, obvious prefixes inside the switch statement.
### Quiz time

> [!question]
> Define an enum class named Animal that contains the following animals: pig, chicken, goat, cat, dog, duck. Write a function named getAnimalName() that takes an Animal parameter and uses a switch statement to return the name for that animal as a std::string_view (or std::string if you’re using C++14). Write another function named printNumberOfLegs() that uses a switch statement to print the number of legs each animal walks on. Make sure both functions have a default case that prints an error message. Call printNumberOfLegs() from main() with a cat and a chicken. Your output should look like this:
```
A cat has 4 legs.
A chicken has 2 legs.
```

```cpp
#include <iostream>
#include <string_view> // C++17
//#include <string> // for C++14

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

constexpr std::string_view getAnimalName(Animal animal) // C++17
// const std::string getAnimalName(Animal animal) // C++14
{
    // If C++20 capable, could use `using enum Animal` here to reduce Animal prefix redundancy
    switch (animal)
    {
        case Animal::chicken:
            return "chicken";
        case Animal::duck:
            return "duck";
        case Animal::pig:
            return "pig";
        case Animal::goat:
            return "goat";
        case Animal::cat:
            return "cat";
        case Animal::dog:
            return "dog";

        default:
            return "???";
    }
}

void printNumberOfLegs(Animal animal)
{
    std::cout << "A " << getAnimalName(animal) << " has ";

    // If C++20 capable, could use `using enum Animal` here to reduce Animal prefix redundancy
    switch (animal)
    {
        case Animal::chicken:
        case Animal::duck:
            std::cout << 2;
            break;

        case Animal::pig:
        case Animal::goat:
        case Animal::cat:
        case Animal::dog:
            std::cout << 4;
            break;

        default:
            std::cout << "???";
            break;
    }

    std::cout << " legs.\n";
}

int main()
{
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);

    return 0;
}
```
---
## Vector
Vector is a template class in STL (Standard Template Library) of C++ programming language. C++ vectors are sequence containers that store elements.
Specifically used to work with dynamic data, C++ vectors may expand depending on the elements they contain. That makes it different from a fixed-size array.
C++ vectors can automatically manage storage. It is efficient if you add and delete data often.

> [!important]  
Bear in mind however, that a vector might consume more memory than an array.
### Why Use Vectors in C++
Vectors C++ are preferable when managing ever-changing data elements.
It is handy if you don’t know how big the data is beforehand since you don’t need to set the maximum size of the container. Since it’s possible to resize C++ vectors, it offers better flexibility to handle dynamic elements.
C++ vectors offer excellent efficiency. It is a template class, which means no more typing in the same code to handle different data.
If you use vectors, you can copy and assign other vectors with ease. There are different ways to do that: 
- using the iterative method
- assignment operator `=`
- an in-built function
- or passing vector as a constructor.

In C++ vectors, automatic reallocation happens whenever the total amount of memory is used. This reallocation relates to how size and capacity function works.
### How to Create C++ Vectors
Vectors in C++ work by declaring which program uses them. The common syntax look like this:
`vector <type> variable (elements)`

For example:
`vector <int> rooms (9);`

Let's break it down:
- `type` - defines a data type stored in vector  (e.g \<int\>, \<double\>, \<string\>)
- `variable` - is a name that you choose for the data
- `elements` - specified the number of elements for the data

> [!NOTE]
> It is mandatory to determine the type and variable name. However, the number of elements is optional.

Basically, all the data elements are stored in contiguous storage. Whenever you want to access or move through the data, you can use iterators.
The data elements in C++ vectors are inserted at the end. Use modifiers to insert new elements or delete existing ones.
#### Iterators
An iterator allows you to access the data elements stored within the C++ vector. It is an object that functions as a pointer. There are five types of iterators in C++: input, output, forward, bidirectional, and random access.
C++ vectors support random access iterators. Here are a few function you may use with iterators for C++ vectors:
- `vector::begin()` returns an iterator to point at the first element of a C++ vector.
- `vector::end()` returns an iterator to point at past-the-end element of a C++ vector.
- `vector::cbegin()` is similar to `vector::begin()`, but without the ability to modify the content.
- `vector::cend()` issimilar to `vector::end()` but can’t modify the content.
#### Modifiers
As its name suggests, you can use a modifier to change the meaning of a specified type of data. Here are some modifiers you can use in C++ vectors:
- `vector::push_back()` pushes elements from the back.
- `vector::insert()` inserts new elements to a specified location.
- `vector::pop_back()` removes elements from the back.
- `vector::erase()` removes a range of elements from a specified location.
- `vector::clear()` removes all elements.
### Constructing a `std::vector` from a Raw Array (Range Constructor)
#### The Code

```cpp
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
}
```

#### Which Constructor Is This?
`std::vector` is overloaded — it has multiple constructors, and the compiler picks the right one based on the **types** of the arguments passed in. This is easy to confuse with the "count" constructor:

```cpp
std::vector<int> a(5); // "count" constructor: 5 default-constructed ints
```

But `vecOfStr(arr, arr + n)` is a **different** constructor entirely — the **range constructor**:

```cpp
vector(InputIt first, InputIt last);
```

It takes **two pointers/iterators**: one to the **first** element to copy, and one to **one-past-the-last** element to copy. It copies everything in that `[first, last)` range into the new vector.
#### Breaking Down the Arguments

```cpp
std::vector<std::string> vecOfStr(arr, arr + sizeof(arr) / sizeof(std::string));
```

- `arr` → pointer to the **first** element (arrays decay to a pointer to their first element)
- `arr + sizeof(arr) / sizeof(std::string)` → pointer to **one past the last** element

> [!NOTE]  The `sizeof(arr) / sizeof(std::string)` 
> 
> This is a classic C-style trick for computing the **element count** of a raw array (only valid when `arr` is an actual array, not a pointer):
> 
> - `sizeof(arr)` → total size in bytes of the whole array
> - `sizeof(std::string)` → size in bytes of _one_ `std::string`
> - Dividing → the number of elements, `n`

In other words:
$$
 first\_block\_of\_array+\frac{size\_of\_array}{elements}
$$


So `arr + n` is pointer arithmetic: start at `arr`, move forward `n` `std::string`-sized steps, landing exactly one position past the last valid element.

```
arr                          arr + n
 |                              |
 v                              v
[elem0][elem1][elem2]...[elemN-1]   (one past the end, not accessed)
 ^-------------- copies this range --------------^
```

#### Why Two Pointers Instead of a Count?
A single pointer (`arr`) doesn't carry information about _how many elements follow it_ — pointers have no built-in sense of length. A second pointer (or an explicit count) is required to mark where copying should stop.
#### Constructor Comparison

| Call                        | Constructor used  | Meaning                        |
| --------------------------- | ----------------- | ------------------------------ |
| `vector<int> a(5)`          | count constructor | 5 default-constructed `int`s   |
| `vector<int> b(arr, arr+5)` | range constructor | copies 5 `int`s **from** `arr` |
Both look like `(x, y)`, but the compiler tells them apart by **argument type**: `(int, int)` matches the count constructor; two pointers of the same type match the range constructor.

### Vector Examples:

```cpp
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
```