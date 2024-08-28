#include "Egzaminator.h"
#include "Test_Student.h"

Egzaminator::Egzaminator(Drukarz* drukarz, Oceniacz* oceniacz, int lTestow ) : drukarz(drukarz), oceniacz(oceniacz),lTestow(lTestow){
    testy = new Test[lTestow]();
}

Egzaminator::~Egzaminator(){
    delete[] testy;
}

void Egzaminator::dodajTest(const Test& t) {
    Test* noweTesty = new Test[lTestow+1];
    for (int i=0; i<lTestow; i++){
        noweTesty[i] = testy[i];
    }
    noweTesty[lTestow ] = t;
    delete[] testy;
    testy = noweTesty;
    lTestow++;
}

void Egzaminator::ocenWszystko(){
    for (int i = 0; i < lTestow; i++) {
        for (int j = 0; j < testy[i].lPytan; j++) {
            oceniacz->ocen(testy[i].pytania[j]);
        }
    }
}

void Egzaminator::drukujWszystko(){
    for (int i = 0; i < lTestow; i++) {
        drukarz->drukuj(testy[i]);
    }
}

int Egzaminator::ocen(Pytanie p) {
    return oceniacz->ocen(p);
}
void Egzaminator::drukuj(Test t) {
    drukarz->drukuj(t);
}