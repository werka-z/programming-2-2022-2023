#include <iostream>
#include <string_view>
using namespace std;

void autoForObjects(){

    //initialization
    auto d{5.0}; // double literal => 'd' is double
    cout << "Value of d: " << d << ", type double\n";

    auto i{1 + 2}; // i is int
    cout << "Value of i: " << i << ", type int\n";

    auto j{i}; // i is an int => j is int
    cout << "Value of j: " << j << ", type int\n";

    //const
    const int x = 5;
    auto y = x; //const dropped
    cout << "Value of y: " << y << ", type int\n";

    const auto z = x; // const reapplied
    cout << "Value of z: " << z << ", type const int\n";

    //string/const char
    auto s = "hi mom"; //const char, not string
    cout << "Value of s: " << s << ", type const char* (not string) \n";


    // "s" and "sv" deduction
    auto s1 { "goo"s };  // string
    cout << "Value of s1: " << s1 << ", type string\n";

    auto s2 { "moo"sv }; // string_view
    cout << "Value of s2: " << s2 << ", type string_view\n";

    // division - if BOTH 'a' and 'b' are ints -> integer division, else float/double division
    auto a { 3 };
    auto b { 2 };
    cout << "Value of a/b: " << a / b << '\n';
}

// function with auto return type - has to be seen from main - defined in main.cpp
// auto add(int x, int y){ return x + y;}  // return type deduced from 'x+y'


// functions with trailing (specified) return type

auto addtrailing(int x, int y) -> int{
    return x + y;
}

auto divide(double x, double y) -> double{
    if (y != 0.0) return x / y;
    else{
        cout << "Error - division by zero!" << endl;
        return 0.0;
    }
}

auto printSomething() -> void{
    cout << "Printing something!" << endl;
}

auto generateSubstring(const string &s, int start, int len) -> string{
    if (start >= 0 && start + len <= s.size()) return s.substr(start, len);
    else{
        cout << "Invalid range!" << endl;
        return "";
    }
}