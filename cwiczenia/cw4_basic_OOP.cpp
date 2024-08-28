#include <iostream>
#include <string>
using namespace std;

class Procesor{
        string marka;
        int taktowanie;

    public:
        Procesor(){
            cout << "konstruktor domyslny klasy procesor" << endl;
            marka = "";
            taktowanie = 0;
        }

        Procesor(string marka_, int taktowanie_){
            cout << "konstruktor z argumentami klasy procesor" << endl;
            marka = marka_;
            taktowanie = taktowanie_;
        }
        void zwiekszTaktowanie(int liczba){
            taktowanie += liczba;
        }
        void zmienjszTaktowanie(int liczba){
            taktowanie -= liczba;
        }
        int getTaktowanie()const{
            return taktowanie;
        }
};

class KGraficzna{
        string nazwa;
        int ROP;

    public:
        KGraficzna(){
            cout << "konstruktor domyslny klasy kGraficzna" << endl;
            nazwa = "";
            ROP = 0;
        }

        KGraficzna(string nazwa_, int ROP_){
            cout << "konstruktor z argumentami klasy kGraficzna" << endl;
            nazwa = nazwa_;
            ROP = ROP_;
        }

        void zmienNazwe(string nowaNazwa){
            nazwa = nowaNazwa;
        }

        void wyswietlROP(){
            cout << ROP << endl;
        }
        int getROP() const {
            return ROP;
        }
};

class RAM{
        int czest;
        int wolnyRAM;

    public:
        RAM(){
            cout << "konstruktor domyslny klasy RAM" << endl;
            czest = 0;
            wolnyRAM = 8;
        }

        RAM(int czest_, int wolnyRAM_){
            cout << "konstruktor z argumentami klasy RAM" << endl;
            czest = czest_;
            wolnyRAM = wolnyRAM_;
        }

        void wyswietlRAM(){
            cout << wolnyRAM << endl;
        }
        int getCzestRAM() const{
            return czest+wolnyRAM;
        }

};

class DyskTw{
        int pojemnosc;
        float RPM;

public:
    DyskTw() : pojemnosc(512), RPM(0){
            cout << "konstruktor domyslny klasy dyskTw" << endl;
    }

    DyskTw(int pojemnosc_, float RPM_ = 0.7){
            cout << "konstruktor 1 z argumentami klasy dyskTw" << endl;
            pojemnosc = pojemnosc_;
            RPM = RPM_;
    }
    int getPojRPM() const {
        return pojemnosc + int(RPM);
    }

    void zapisPlikow(int gb){
        cout << "zwolnienie " << gb << " GB pamieci" << endl;
        pojemnosc -= gb;
    }
    void usunieciePlikow(int gb){
        cout << "zaplenienie " << gb << " GB pamieci" << endl;
        pojemnosc += gb;
    }

};

class KontrolerUSB{
        string port;
        string marka;

    public:
        KontrolerUSB(){
            cout << "konstruktor domyslny klasy kontrolerUSB" << endl;
            port = "";
            marka = "";
        }
        KontrolerUSB(string port_, string marka_){
            cout << "konstruktor z argumentami klasy kontrolerUSB" << endl;
            port = port_;
            marka = marka_;
        }
};

class Komputer {
    Procesor procesor;
    KGraficzna kGraficzna;
    RAM ram;
    DyskTw dyskTw;
    KontrolerUSB kontrolerUSB;

public:
    Komputer() : procesor(), kGraficzna(), ram(), dyskTw(), kontrolerUSB(){
        cout << "konstruktor domyslny klasy komputer" << endl;
    }

    Komputer(Procesor p, KGraficzna kg, RAM r, DyskTw d, KontrolerUSB k)
    : procesor(p), kGraficzna(kg), ram(r), dyskTw(d), kontrolerUSB(k){
        cout << "konstruktor z argumentami klasy Komputer" << endl;
    }

    void zmniejszTaktowanie(int liczba){
        cout << "zmniejszanie taktowania o "<< liczba<< " przez klase Komputer" << endl;
        procesor.zmienjszTaktowanie(liczba);
    }

    void wyswietlRAM(){
        cout << "wyswietlanie ramu z klasy Komputer" << endl;
        ram.wyswietlRAM();
    }

    void podmienProcesor(const Procesor &p){
        cout << "podmianka procesora" << endl;
        procesor = p;
    }

    void obliczWydajnosc(){
        int sum = procesor.getTaktowanie()+kGraficzna.getROP()+ram.getCzestRAM();
        cout << "Ogolna wydajnosc komputera to " << 1000 - sum << endl;
    }
    void zapisDoPamieci(int gb){
        cout << "zapis do pamieci z klasy Komputer" << endl;
        dyskTw.zapisPlikow(gb);
    }
    void zwolnieniePamieci(int gb){
        cout << "zapis do pamieci z klasy Komputer" << endl;
        dyskTw.usunieciePlikow(gb);
    }
};