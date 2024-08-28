#include <array>
#include <algorithm>
#include <iostream>

using namespace std;

void initializeArray() {
    cout << "Initializing arrays...\n";

    array<int, 5> a0 {9, 7, 5, 3, 1}; // list initialization
    array arr1 {9.7, 7.31}; // array<double, 2>

    auto myArray1 { to_array<int, 5>({ 9, 7, 5, 3, 1 }) }; // specify type and size

    array<int, 5> arr3;
    arr3 = {0, 1, 2, 3, 4 }; // OK
    arr3 = {9, 8, 7 }; // OK, rest is set to 0

    array arr4 {9, 7, 5, 3, 1 };
    arr4.at(1) = 6; // element 1 is valid
    // arr4.at(9) = 10; // out of bounds
    cout << a0[1] << '\n';
}

void demonstrateSize() {
    array arr5 {9.0, 7.2, 5.4, 3.6, 1.8 };
    cout << "Length: " << arr5.size() << '\n';
}

void demonstrateSorting() {
    cout << "Sorting...\n";

    array myArray { 7, 3, 1, 9, 5 };
    sort(myArray.begin(), myArray.end()); // sort from <algorithm>

    for (int element : myArray)
        cout << element << ' ';
}

template <typename T, std::size_t size> // template element type and size
void printArray(const array<T, size>& myArray) {
    for (auto element : myArray)
        cout << element << ' ';
    cout << '\n';
}

struct House {
    int number{};
    int stories{};
    int roomsPerStory{};
};

void demonstrateStructArray() {
    cout << "Array of houses:\n";

    array<House, 3> houses {
            { { 13, 4, 30 }, { 14, 3, 10 }, { 15, 3, 40 } }
    };

    for (const auto& house : houses) {
        cout << "House number " << house.number
             << " has " << (house.stories * house.roomsPerStory)
             << " rooms\n";
    }
}
