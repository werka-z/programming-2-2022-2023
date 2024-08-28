#include <iostream>
#include <fstream>
#include "Drukarz.h"
#include "Test_Student.h"
#include "Pytanie.h"
using namespace std;


void DrukarzCSV::drukuj(Test t){
    counter++;
    string filename = "CSV_" + to_string(counter);
    ofstream file(filename);
    if (!file){
        cerr<< "Nie można otworzyć pliku "<< filename<< "do zapisu\n";
        return;
    }
    string csv = t.toCSV();
    file << csv;
}

void DrukarzJSON::drukuj(Test t){
    counter++;
    string filename = "JSON_" + to_string(counter);
    ofstream file(filename);
    if (!file){
        cerr<< "Nie można otworzyć pliku "<< filename<< "do zapisu\n";
        return;
    }
    string csv = t.toJSON();
    file << csv;
}

void DrukarzStdout::drukuj(Test t){
    t.student.display();
    for (int i=0; i<t.lPytan; i++){
        t.pytania[i].display();
    }
}