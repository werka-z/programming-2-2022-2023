//Weronika Zygis
#include <string>
#include <cstdarg>
using std::string;


//--------------va_list-------------------
//-------------helpers-------------------

string rmZeros(const string& a);
void rmFirst(string& a);
string addStrings(const string& a, const string& b);
string minusAtBeg(string& a);


string multiplyWithDigit(const string& a, int digit, int idxA, int carry) {
    if (idxA < 0 && carry == 0) return "";

    int dgtA = idxA >= 0 ? (a[idxA] - '0') : 0;
    int product = dgtA * digit + carry;
    carry = product / 10;

    string result = multiplyWithDigit(a, digit, idxA - 1, carry);
    result += (product % 10) + '0';
    return result;
}
string makeZeros(int count) {
    if (count <= 0) return "";
    return "0" + makeZeros(count - 1);
}

string multStringsRecursive(const string& a, const string& b, int idxB, string& sum) {
    if (idxB < 0) return sum;
    if(a=="0" || b=="0") return "0";

    int dgtB = b[idxB] - '0';
    string zeros = makeZeros(b.size()-1-idxB);
    string product = multiplyWithDigit(a, dgtB, a.size() - 1, 0);
    product += zeros;
    sum = addStrings(sum, product);

    return multStringsRecursive(a, b, idxB - 1, sum);
}

string multStrings(const string &a, const string &b){
    if (a=="0" || b=="0") return "0";

    string aCopy = a;
    string bCopy = b;

    if (aCopy[0]=='+') rmFirst(aCopy);
    if (bCopy[0]=='+') rmFirst(bCopy);
    bool negA = (aCopy[0] == '-');
    bool negB = (bCopy[0] == '-');

    string result;

    if (negA == negB){
        if (negA){ //both are negative
            rmFirst(aCopy);
            rmFirst(bCopy);
        }
        if (aCopy[0] == '0') aCopy = rmZeros(aCopy);
        if (bCopy[0] == '0') bCopy = rmZeros(bCopy);
        string sum = "0";
        result = multStringsRecursive(aCopy, bCopy, bCopy.size() - 1, sum);
        result = rmZeros(result);
    }
    else{
        if (negA) rmFirst(aCopy);
        if (negB) rmFirst(bCopy);
        string sum = "0";
        result = multStringsRecursive(aCopy, bCopy, bCopy.size() - 1, sum);
        result = rmZeros(result);
        result = minusAtBeg(result);
    }
    if(result=="-0") result = "0";
    result = rmZeros(result);
    return result;
}
string vaMult(int arg_num, va_list args){
    if (arg_num == 0) return "1";
    string arg(va_arg(args, const char*));
    if (arg[0]=='+') rmFirst(arg);
    arg = rmZeros(arg);
    string nextProduct = vaMult(arg_num-1, args);
    if (nextProduct[0]=='+') rmFirst(nextProduct);
    nextProduct = rmZeros(nextProduct);
    return multStrings(arg,nextProduct);
}

//-----------------------functions------------------------

string Mult ( int arg_num, ... ){
    if (arg_num<2) return "";
    va_list args;
    va_start(args, arg_num);
    string result = vaMult (arg_num, args);
    va_end(args);
    return result;
}
void Mult ( string* result, int arg_num, ...){
    if (arg_num<2) return;
    va_list args;
    va_start(args, arg_num);
    *result = vaMult (arg_num, args);
    va_end(args);
}
void Mult ( string& result, int arg_num, ... ){
    if (arg_num<2) return;
    va_list args;
    va_start(args, arg_num);
    result = vaMult (arg_num, args);
    va_end(args);
}

//-------------------- const string* --------------------
//-----------------------helpers-------------------------
string multHelper(const string* arguments, int arg_num, int idx, const string& currentProd){
    if (idx == arg_num){
        string result = currentProd;
        if (result[0]=='+') rmFirst(result);
        result= rmZeros(result);
        return result;
    }
    if(arguments[idx]=="0" || currentProd == "0") return "0";
    if(arguments[idx] == "1") {
        string prod = currentProd;
        if (prod[0]=='+') rmFirst(prod);
        prod = rmZeros(prod);
        return multHelper(arguments, arg_num, idx+1, prod);
    }
    if(currentProd == "1"){
        string arg = arguments[idx];
        if(arg[0]=='+') rmFirst(arg);
        arg = rmZeros(arg);
        return multHelper(arguments, arg_num, idx+1, arg);
    }

    string product = multStrings(currentProd, arguments[idx]);
    if (product[0] == '+') rmFirst(product);
    product = rmZeros(product);
    return multHelper(arguments, arg_num, idx+1, product);
}

//---------------------functions-------------------------
string Mult (int arg_num, const string* args){
    if (arg_num <2) return "";
    return multHelper(args, arg_num, 1, args[0]);
}
void Mult ( string* result, int arg_num, const string* args){
    if (arg_num<2) return;
    *result = Mult(arg_num, args);
}
void Mult ( string& result, int arg_num, const string* args){
    if (arg_num<2) return;
    result = Mult(arg_num, args);
}