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