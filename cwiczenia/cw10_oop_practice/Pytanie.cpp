#include "Pytanie.h"
#include <iostream>
#include <sstream>
using namespace std;

Pytanie::Pytanie(): lOdp(0), odp(nullptr) {}

Pytanie::Pytanie(int a) {
    this->lOdp = a;
    this->odp = new Odp[a];
}

Pytanie::~Pytanie() {
    delete odp;
}

int Pytanie::getTP(){
    int counter = 0;
    for (int i=0; i<lOdp; i++){
        if (odp[i]==TP) counter++;
    }
    return counter;
}

int Pytanie::getFP(){
    int counter = 0;
    for (int i=0; i<lOdp; i++){
        if (odp[i]==FP) counter++;
    }
    return counter;
}

int Pytanie::getTN(){
    int counter = 0;
    for (int i=0; i<lOdp; i++){
        if (odp[i]==TN) counter++;
    }
    return counter;
}

int Pytanie::getFN(){
    int counter = 0;
    for (int i=0; i<lOdp; i++){
        if (odp[i]==FN) counter++;
    }
    return counter;
}

int Pytanie::getlOdp() const {
    return lOdp;
}

Odp Pytanie::getOdp(int i) const {
    return odp[i];
}

string Pytanie::getOdpStr(int i) const{
    switch (getOdp(i)) {
        case TN:
            return "TN";
        case TP:
            return "TP";
        case FN:
            return "FN";
        case FP:
            return "FP";
    }
    return "0";
}

void Pytanie::setOdp(int nr, Odp odp_){
    if (nr >= lOdp || nr < 0) {
        cout << "Nie ma podpunktu o takim numerze." << endl;
        return;
    }

    odp[nr] = odp_;
}

string Pytanie::toJSON() const{
    return "";
}
string Pytanie::toCSV() const{
    return "";
}
void Pytanie::display() {
    cout << odp;
}



