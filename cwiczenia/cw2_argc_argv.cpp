#include <iostream>
#include <cstdarg>

//using namespace std;

int dodajInt(int argc, ...){
    va_list ap;

    va_start(ap, argc);

    int result =0;
    for (int i=0; i<argc; i++){
        result += va_arg(ap, int);
    }
    va_end(ap);
    return result;
}
double dodajDouble(int argc, ...){
    va_list ap;
    va_start(ap, argc);

    double result =0;
    for (int i=0; i<argc; i++){
        result += va_arg(ap, double);
    }
    va_end(ap);
    return result;
}

//int main()
//{
//    cout << dodajInt(4, 1, 1, 1, 1) << endl;
//    cout << dodajDouble(4, 4.1, 4.1, 4.1, 4.1) << endl;
//
//    cin.ignore();
//    return 0;
//}
