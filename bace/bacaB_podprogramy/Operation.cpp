//Weronika Zygis
#include <string>
#include <cstdarg>
using namespace std;

//-----------------------va_list-----------------------
//-----------------------helpers----------------------
string addStringsRecursive(const string& a, const string& b, int idxA, int idxB, int carry);
string vaSum(int arg_num, va_list args);
string makeZeros(int count);
string multStringsRecursive(const string& a, const string& b, int idxB, string& sum);
string vaMult(int arg_num, va_list args);

void opHelperRecursive(string* arguments, string (*operationFunc)(int, const string*), int arg_num, int idx, va_list args) {
    if (idx == arg_num) return;
    arguments[idx] = va_arg(args, const char*);
    opHelperRecursive(arguments, operationFunc, arg_num, idx + 1, args);
}

string opHelper(string (*operationFunc)(int, const string*), int arg_num, va_list args) {
    string* arguments = new string[arg_num];
    opHelperRecursive(arguments, operationFunc, arg_num, 0, args);
    string result = operationFunc(arg_num, arguments);
    delete[] arguments;
    return result;
}

void fillStringsArray(string* arr, int idx, int count, va_list args) {
    if (idx >= count) return;

    const char* str = va_arg(args, const char*);
    if (str == NULL) return;
    arr[idx] = string(str);
    fillStringsArray(arr, idx + 1, count, args);
}

string* vaToStrings(int arg_num, va_list args) {
    if (arg_num < 1) return NULL;

    string* arr = new string[arg_num];
    fillStringsArray(arr, 0, arg_num, args);

    return arr;
}

//---------------------functions-----------------------

string Operation (string (*opFunction)( int, const string* ), int arg_num, ...) {
    if (arg_num<2) return "";
    va_list args;
    va_start(args, arg_num);
    string result = opHelper(opFunction, arg_num, args);
    va_end(args);
    return result;
}
void Operation (string* result, string (*opFunction)( int, const string* ), int arg_num, ... ){
    if (arg_num<2) return;
    va_list args;
    va_start(args, arg_num);
    *result = opHelper(opFunction, arg_num, args);
    va_end(args);
}
void Operation (string& result, void (*opFunction)(string*, int, const string*), int arg_num, ... ){
    if (arg_num<2) return;
    va_list args;
    va_start(args, arg_num);
    string* strings = vaToStrings(arg_num, args);
    va_end(args);
    opFunction(&result, arg_num, strings);
    delete[] strings;
}


//-----------------------va_list-----------------------
//-----------------------helpers----------------------

//---------------------functions-----------------------

string Operation (string (*opFunction)( int, const string* ), int arg_num, const string* args){
    return opFunction(arg_num, args);
}
void Operation ( string* result, string (*opFunction)( int, const string* ), int arg_num, const string* args){
    *result = opFunction(arg_num, args);
}
void Operation ( string& result, void (*opFunction)( string*, int, const string* ), int arg_num, const string* args){
    opFunction(&result, arg_num, args);
}