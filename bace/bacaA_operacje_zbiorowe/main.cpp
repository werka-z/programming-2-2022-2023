#include <iostream>
#include <string>
using namespace std;

//working:
bool Emptiness (int set);
int Cardinality(int set);
bool Nonempty(int set);
bool LessThen(int A, int B); //probably
bool LessEqual(int A, int B); //probs
bool GreatEqual(int A, int B);//probs
bool GreatThen (int A, int B); //probably
bool Disjoint(int A, int B);
bool Conjunctive(int A, int B);
bool Inclusion(int A, int B);
bool Equality(int A, int B);
void Union (int A, int B, int* result);
void Intersection (int A, int B, int* result);
void Symmetric (int A, int B, int* result);
void Difference (int A, int B, int* result);
void Complement (int set, int* result);

void Emplace (char* input, int* result_set);
void Insert(char* input, int* target_set);
void Erase(char* input, int* result_set);
void Print(int set, char* result);
bool Member(char* subset, int set);
void Print(int, char*);
void Emplace (char*, int*);
int Strtoint(char*, int);

int main() {

    int set_1 = stoi("00000000000000000000000000000000", nullptr, 2);
    int set_2 = stoi("00000000000000000000000000000000", nullptr, 2);
    int set_3 = stoi( "0100000011000100001000000001001", nullptr, 2);
    int set_4 = stoi( "0100001000100010000001000000101", nullptr, 2);

    char napis[256];
    Print(-2147483648, napis);
    cout << napis << endl;
    Print(-3, napis);
    cout << napis << endl;
    Print(4, napis);
    cout << napis << endl;
    Print(7, napis);
    cout << napis << endl;

    //Emplace("11111", set_1);
//    char napis[256];
//    int x, y;
//    cout << Cardinality(0) << endl;
//    cout << Cardinality(1) << endl;
//    cout << Cardinality(4) << endl;

    //cout << Cardinality(set_1) << endl << Cardinality(set_2) << endl << Cardinality(set_3) << endl;
    //cout << LessEqual(set_3, set_4) << endl << LessThen(set_4, set_3);
//        cout << set_1 << endl;
//    Insert("00000 11110 00010", &set_1);//00000 00001 00010
//    cout << set_1 << endl;
//    Erase("11110 00010", &set_1);
//    cout << set_1 << endl;
//    Erase("00000 00000", &set_1);
//    cout << set_1 << endl;




////   ------- przechodza w miare --------------
    Emplace("11111", &set_2);
    cout << set_2 << endl;
//    char napi[5] = {'1', '1', '1', '1', '1'};
//    cout << set_1 << endl;
//    Insert("00000 11110 00010", &set_1);//00000 00001 00010
//    cout << set_1 << endl;
//    Emplace("01111 00010", &set_1);
//    cout << set_1 << endl;
//    cout << Cardinality(set_3) << endl;
//    Print(-2147483648, napis);
//    cout << napis << endl;
    //Union(set_2, set_3, &result);
    //cout << "result: " << result << endl;

    return 0;
}

//void PrintHlpr(int set, int i, char* result, int index) {
//    if (i < 0) {
//        *(result + index) = '\0';
//        return;
//    }
//    if (set & (1 << i)) {
//        *(result + index  ) = (char)('0' + ((i>>4)%2));
//        *(result + index+1) = (char)('0' + (i>>3) % 2);
//        *(result + index+2) = (char)('0' + ((i>>2) %2));
//        *(result + index+3) = (char)('0' + ((i>>1) %2));
//        *(result + index+4) = (char)('0' + (i % 2));
//        if (i != 0) *(result + index + 5) = ' ';
//        index += (i == 0) ? 5 : 6;
//    }
//    PrintHlpr(set, i - 1, result, index);
//}
//
//void Print(int set, char* result) {
//    if (set == 0) {
//        result[0] = 'e';
//        result[1] = 'm';
//        result[2] = 'p';
//        result[3] = 't';
//        result[4] = 'y';
//        result[5] = '\0';
//    } else {
//        PrintHlpr(set, 31, result, 0);
//    }
//}
//void Print(int set, string result){
//    result ="";
//
//    for (int i=31; i>0; i--){
//        if (set & (1<<i))  result += ((to_string(i)) + " ");
//    }
//}

//int input_length(const char* input){
//    if (*input == '\0') {
//        return 0;
//    }
//    return input_length(input + 1) + 1;
//}
//
//int read(char* input);
//int strtoint (char*);
//void insert(char* input, int* set)
//{
//    if (*input == '\0') return; //koniec inputu
//    if (*input == '0' || *input == '1')
//        *set |= strtoint(input);
//
//    insert(input + 1, set); //->kolejny char
//}