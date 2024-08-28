#include <vector>
#include <iostream>

using namespace std;

void initializeVector() {
    cout << "Vector initialization... ";

    vector<int> v2 = { 9, 7, 5, 3, 1 }; // initializer list (older)
    vector v3 { 9, 7, 5, 3, 1 }; // uniform initialization

    // v[6] = 2; // out of bounds
    // v.at(7) = 3; // out of bounds

    vector v4 = { 0, 1, 2, 3, 4 }; // ok, vector length 5
    v4 = { 9, 8, 7 }; // ok, vector length 3

    cout << " done.\n";
}

void demonstrateVectorSize() {
    vector v5 {9, 7, 5, 3, 1 };
    cout << "The length of the vector is: " << v5.size() << "\n";

    vector<int> empty {};
    cout << "The length of empty vector: " << empty.size() << '\n';

    vector v6 { 0, 1, 2 };
    v6.resize(5); // set size to 5
    cout << "Resized length: " << v6.size() << '\n';

    vector v7 { 0, 1, 2, 3, 4 };
    v7.resize(3); // set length to 3
    cout << "Resized length: " << v7.size() << '\n';
}

void demonstrateVectorInitialization() {
    cout << "Vector initialization... ";

    vector<int> v8(5);
    cout << " length: " << v8.size() << " ";
    for (int i : v8)
        cout << i << ' ';
}

void demonstrateVectorOfBool() {
    cout << "\nVector of bools: ";

    vector<bool> v9{ true, false, false, true, true };
    cout << " length: " << v9.size() << "     ";
    for (int i : v9)
        cout << i << ' ';
}




