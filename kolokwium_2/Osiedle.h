#ifndef KOLOKWIUM2_OSIEDLE_H
#define KOLOKWIUM2_OSIEDLE_H

#include <vector>
#include <iostream>
#include "Budynki.h"
using namespace std;


template <typename T>
class Osiedle {
    static vector<T> osiedle;

public:
    Osiedle(int l) {
        osiedle = vector<T>(l);
    };

    T& operator[](int idx){
        if (idx > osiedle.size() || idx <1 ) throw out_of_range("Nieprawidlowy numer dzialki\n");
        else return osiedle[idx+1];
    }


    friend ostream &operator<<(ostream& os, const Osiedle<T>& t){
        for (auto i : osiedle){
            os << osiedle[i];
            if (i != osiedle.size() - 1) os << " / ";
        }
        return os;
    }

};


#endif //KOLOKWIUM2_OSIEDLE_H
