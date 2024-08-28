#include <iostream>
#include <string>
#include <cstdarg>
#include <fstream>
using namespace std;

void rozdzielNaHex (string plikWejscie, int liczbaWyjsc, string plikWyjscie1, ...)
{
    //utworzenie i otwarcie strumieni, ustawienie listy [...]
    va_list ap;
    va_start(ap, plikWyjscie1);

    ofstream *output = new ofstream[liczbaWyjsc];
    output[0].open(plikWyjscie1);
    for (int i=1; i<liczbaWyjsc; i++){
        output[i].open(va_arg(ap, char*));
    }
    va_end(ap);
    ifstream input(plikWejscie);


    //ustawienie flag
    ios::fmtflags flagi = cout.flags();
    cout.unsetf(ios::dec);
    cout.setf(ios::uppercase | ios::hex);


    //przepisywanie
    int k=0;
    string line;
    while (getline(input, line)){
        int lineint = stoi(line);
        output[k].copyfmt(cout);
        output[k] << lineint << endl;
        k = (k+1) % liczbaWyjsc;
    }

    //zamkniecie strumieni, cofniecie flag, zwolnienie pamieci
    for (int i=0; i<liczbaWyjsc; i++){
        output[i].close();
    }

    delete[] output;
    input.close();
    cout.flags(flagi);
}

void polaczNaDec(string plikWyjscie, int liczbaWejsc, string plikWejscie1, ...)
{
    //utworzenie i otworzenie strumieni, ustawienie listy [...]
    va_list ap;
    va_start(ap, plikWejscie1);

    ifstream *input = new ifstream[liczbaWejsc];
    input[0].open(plikWejscie1);
    for (int i=1; i<liczbaWejsc; i++){
        input[i].open(va_arg(ap, char*));
    }

    va_end(ap);
    ofstream output(plikWyjscie);

    //przepisywanie
    int k=0;
    string line;
    while (getline(input[k], line)){
        int lineint = stoi(line, nullptr, 16);
        output << lineint << endl;
        k = (k+1) % liczbaWejsc;
    }

    //zamkniecie strumieni, zwolnienie pamieci
    for (int i=0; i<liczbaWejsc; i++){
        input[i].close();
    }
    output.close();
    delete[] input;
}


int main(){
    rozdzielNaHex("plik_1", 3, "plika","plikb", "plikc");
    //polaczNaDec("plik_1", 4, "plika","plikb", "plikc", "plikd");

    return 0;
}