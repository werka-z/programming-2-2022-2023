//Weronika Zygis
#include <string>
#include <cstdarg>
using std::string;

//-------------va_list------------------
//-------------helpers-------------------
bool FirstGreater(string a, string b){
    if (a.size()>b.size()) return true;
    if (a.size()<b.size()) return false;
    else return a>b;
}

string minusAtBeg(string& a) {
    string result = "-";
    result += a;
    return result;
}


void rmZerosHelpr(const string& a, string& result, int idx, bool neg) {
    if (idx >= a.size()) {
        //if(result.empty()) result = "0";
        return;
    }
    if (!result.empty() || a[idx] != '0') {
        result += a[idx];
    }
    rmZerosHelpr(a, result, idx + 1, neg);
}

string rmZeros(const string& a){
    string result;
    bool neg = (a[0] == '-');
    int startIdx = neg ? 1:0;
    rmZerosHelpr(a, result, startIdx, neg);

    if(neg && !result.empty() && result[0] != '-'){
        result = minusAtBeg(result);
    }

    return result.empty() ? "0" : result;
}

void rmFirst(string& a) {
    if (!a.empty()) a.erase(0, 1);
}

string addStringsRecursive(const string& a, const string& b, int idxA, int idxB, int carry) {
    if (idxA < 0 && idxB < 0 && carry == 0) return "";

    int dgtA = idxA >= 0 ? a[idxA] - '0' : 0;
    int dgtB = idxB >= 0 ? b[idxB] - '0' : 0;
    int sum = dgtA + dgtB + carry;
    carry = sum / 10;

    return addStringsRecursive(a, b, idxA - 1, idxB - 1, carry) + (char)((sum%10)+'0');
}
//works only if a > b
string subtractStringsRecursive(const string& a, const string& b, int idxA, int idxB, int borrow) {
    if (idxA < 0 && idxB < 0 && borrow == 0) return "";
    //if (a<b) return "";

    int dgtA = idxA >= 0 ? a[idxA] - '0' : 0;
    int dgtB = idxB >= 0 ? b[idxB] - '0' : 0;
    int diff = dgtA - dgtB - borrow;

    if (diff < 0) {
        diff += 10;
        borrow = 1;
    }
    else borrow = 0;

    string partial = subtractStringsRecursive(a, b, idxA-1, idxB-1, borrow);
    if (idxA >= 0 && diff >= 0) partial += (char)((diff%10) + '0');
    return partial;
}

string addStrings(const string& a, const string& b) {
    if (a=="0") {
        string result = b;
        if (b[0] == '+') rmFirst(result);
        rmZeros(result);
        return result;
    }
    if (b=="0") {
        string result = a;
        if (a[0]== '+') rmFirst(result);
        rmZeros(result);
        return result;
    }

    string aCopy = a;
    string bCopy = b;

    if (a[0]=='+') rmFirst(aCopy);
    if (b[0]=='+') rmFirst(bCopy);
    bool negA = (a[0] == '-');
    bool negB = (bCopy[0] == '-');

    string result;
    if (negA && negB){//1. A neg, B neg - remove the - from both, addrecmini, add '-'
        rmFirst(aCopy);
        rmFirst(bCopy);
        if (a[0] == '0') aCopy = rmZeros(aCopy);
        if (bCopy[0]=='0') bCopy = rmZeros(bCopy);
        result = addStringsRecursive(aCopy, bCopy, aCopy.size() - 1, bCopy.size() - 1, 0);
        result = minusAtBeg(result);
    }
    else if (negA){ //2. A neg, B pos - remove the - from A, substractrec(b-a)
        rmFirst(aCopy);
        if (aCopy[0] == '0') aCopy = rmZeros(aCopy);
        if (bCopy[0]=='0') bCopy = rmZeros(bCopy);
        bool A_greater = FirstGreater(aCopy, bCopy);
        if (aCopy == bCopy) result = "0";
        else if (A_greater){
            result = subtractStringsRecursive(aCopy, bCopy, aCopy.size() - 1, bCopy.size() - 1, 0);
            result = rmZeros(result);
            result = minusAtBeg(result);
        }
        else result = subtractStringsRecursive(bCopy, aCopy, bCopy.size() - 1, aCopy.size() - 1, 0);
        result = rmZeros(result);
    }
    else if (negB){ //3. A pos, B neg - remove the - from B, substractrec(a-b)
        rmFirst(bCopy);
        if (aCopy[0] == '0') aCopy = rmZeros(aCopy);
        if (bCopy[0]=='0') bCopy = rmZeros(bCopy);
        bool B_greater = FirstGreater(bCopy, aCopy);
        if (aCopy == bCopy) result = "0";
        else if (B_greater){
            result = subtractStringsRecursive(bCopy, aCopy, bCopy.size() - 1, aCopy.size() - 1, 0);
            result = rmZeros(result);
            result = minusAtBeg(result);
        }
        else result = subtractStringsRecursive(aCopy, bCopy, aCopy.size() - 1, bCopy.size() - 1, 0);
        result = rmZeros(result);
    }
    else {//4. A pos, B pos - addstringsrecursive
        result = addStringsRecursive(aCopy, bCopy, aCopy.size() - 1, bCopy.size() - 1, 0);
    }
    result = rmZeros(result);
    if (result == "-0") result = "0";
    return result;
}

string vaSum(int arg_num, va_list &args){
    if (arg_num == 0) return "0";
    string arg(va_arg(args, const char*));
    string nextSum = vaSum(arg_num-1, args);
    if(arg[0] == '+') rmFirst(arg);
    arg = rmZeros(arg);
    nextSum = rmZeros(nextSum);
    return addStrings(arg, nextSum);
}

//-----------functions-------------------
string Sum(int arg_num, ...){
    if (arg_num < 2) return "";
    va_list args;
    va_start(args, arg_num);
    string result = vaSum (arg_num, args);
    va_end(args);
    return result;
}

void Sum(string* result, int arg_num, ...){
    if (arg_num <2 ) return;
    va_list args;
    va_start(args, arg_num);
    *result = vaSum(arg_num, args);
    va_end(args);
}

void Sum(string& result, int arg_num, ...){
    if (arg_num <2) return;
    va_list args;
    va_start(args, arg_num);
    result = vaSum(arg_num, args);
    va_end(args);
}

//--------------- const string* -----------
//----------------helpers-----------------

string sumHelper(const string* arguments, int arg_num, int idx){
    if (idx == arg_num-1) return arguments[idx];

    string partialSum = sumHelper(arguments, arg_num, idx +1);
    if (partialSum[0]=='+') rmFirst(partialSum);
    partialSum = rmZeros(partialSum);
    string arg = rmZeros(arguments[idx]);
    return addStrings(arg, partialSum);
}

//---------------functions---------------

string Sum(int arg_num, const string* args){
    if (arg_num < 2) return "";
    return sumHelper(args, arg_num, 0);
}

void Sum(string* result, int arg_num, const string* args){
    if (arg_num < 2) return;
    string res = sumHelper(args, arg_num, 0);
    *result = res;
}

void Sum(string& result, int arg_num, const string* args){
    if(arg_num<2) return;
    string res = sumHelper(args, arg_num, 0);
    result = res;
}