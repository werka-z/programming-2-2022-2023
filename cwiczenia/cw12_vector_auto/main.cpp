#include <iostream>
#include <array>
using namespace std;


void autoForObjects();
auto add(int x, int y){
    return x + y;  // return type deduced from 'x+y'
}
auto addtrailing(int x, int y) -> int;
auto divide(double x, double y) -> double;
auto printSomething() -> void;
auto generateSubstring(const std::string &s, int start, int len) -> std::string;

void initializeArray();
void demonstrateSize();
void demonstrateSorting();
template <typename T, std::size_t size> // has to be seen from main (either definition or header)
void printArray(const std::array<T, size>& myArray) {
    for (auto element : myArray)
        cout << element << ' ';
    cout << '\n';
}
void demonstrateStructArray();

void initializeVector();
void demonstrateVectorSize();
void demonstrateVectorInitialization();
void demonstrateVectorOfBool();

int main() {

    cout << "Auto:" << endl;
    autoForObjects();

    cout << "The sum (deduced return type): " << add(5, 6) << '\n';
    cout << "The sum (trailing return type): " << addtrailing(5, 6) << '\n';

    cout << "Division result is: " << divide(10.0, 2.0) << '\n';

    printSomething();

    string substring = generateSubstring("learning type deduction!", 0, 12);
    cout << "The generated substring is: " << substring << '\n';


    cout <<endl << "--------------------------" << endl;
    cout << "Arrays:" << endl;
    initializeArray();
    demonstrateSize();
    demonstrateSorting();
    array myArray5{ 9.0, 7.2, 5.4, 3.6, 1.8 };
    printArray(myArray5);
    demonstrateStructArray();

    cout << endl << "--------------------------" << endl;
    cout << "Vectors:" << endl;

    initializeVector();
    demonstrateVectorSize();
    demonstrateVectorInitialization();
    demonstrateVectorOfBool();

}
/*
output:

Auto:
Value of d: 5, type double
Value of i: 3, type int
Value of j: 3, type int
Value of y: 5, type int
Value of z: 5, type const int
Value of s: hi mom, type const char* (not string)
Value of s1: goo, type string
Value of s2: moo, type string_view
Value of a/b: 1
The sum (deduced return type): 11
The sum (trailing return type): 11
Division result is: 5
Printing something!
The generated substring is: learning typ

--------------------------
Arrays:
Initializing arrays...
7
Length: 5
Sorting...
1 3 5 7 9 9 7.2 5.4 3.6 1.8
Array of houses:
House number 13 has 120 rooms
House number 14 has 30 rooms
House number 15 has 120 rooms

--------------------------
Vectors:
Vector initialization...  done.
The length of the vector is: 5
The length of empty vector: 0
Resized length: 5
Resized length: 3
Vector initialization...  length: 5 0 0 0 0 0
Vector of bools:  length: 5     1 0 0 1 1

 */




