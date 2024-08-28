#include "Budynki.h"
#include <iostream>
#include <string>
using namespace std;

Blok::Blok() {};

Blok::Blok(string u): Budynek() {
    typ = "Blok";
    ulica = u;
}

void Blok::wyswietlWiek() {
    cout << "Blok " << ulica << " ma " << wiek << " lat.";
}

Dom::Dom() : Budynek(){};

Dom::Dom(string u): Budynek(){
    typ = "Dom";
    ulica = u;
}

void Dom::wyswietlWiek() {
    cout << "Dom " << ulica << " ma " << wiek << " lat.";
}

Garaz::Garaz() : Budynek() {};

void Garaz::wyswietlWiek() {
    cout << "Garaz " << ulica << " ma " << wiek << " lat.";
}

Garaz::Garaz(string u) : Budynek(){
    typ = "Garaz";
    ulica = u;
}

DomZGarazem::DomZGarazem() : Budynek(){};

void DomZGarazem::wyswietlWiek() {
    cout << "Dom z garazem " << ulica << " ma " << wiek << " lat.";
}

DomZGarazem::DomZGarazem(string ul) : Dom(ul), Garaz(ul), Budynek() {
    typ = "Dom z garazem";
}

ostream& operator<<(ostream& os, const Blok &a){
    os << a.ulica;
    return os;
}

ostream& operator<<(ostream& os, const Dom &a){
    os << a.ulica;
    return os;
}

ostream& operator<<(ostream& os, const Garaz &a){
    os << a.ulica;
    return os;
}

ostream& operator<<(ostream& os, const DomZGarazem &a){
    os << a.ulica;
    return os;
}

