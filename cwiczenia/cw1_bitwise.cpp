#include <iostream>
#include <string>
using namespace std;

unsigned char zakoduj(string napis) // napis zlozony z 8 zer i jedynek -> binarna reprezentacje w zmiennej char
{
    int val = 0;
    for (int i=0; i<8; i++) {
        val <<= 1;
        if (napis[i] == '1')
            val += 1;
    }
    return (unsigned char) val;
}

string odkoduj(unsigned char d){
    int c = (int)d;
    string result;

    for (int i = 128; i > 0; i /= 2){
        if (c / i){
            result+= "1";
            c -= i;
        }
        else result += "0";
    }
    return result;
}
unsigned char zaszyfruj(unsigned char tekst, unsigned char klucz) //szyfrowanie xorem
{
    return ((tekst & (~klucz)) | ((~tekst) & klucz));
}
unsigned char odszyfruj(unsigned char kod, unsigned char klucz) //odszyfrowywanie XOR-em
{
    return ((kod & (~klucz)) | ((~kod) & klucz));
}
string zaszyfruj(string tekst, string klucz) // szyfruje XOR-em tekst zlozony z dowolnej liczby zer i jedynek (z main)
{
    string result;
    long long int tekstint = stoi(tekst, nullptr, 2); //string -> dec
    long long int kluczint = stoi(klucz, nullptr, 2);
    long long int resultxor = ((tekstint & (~kluczint)) | ((~tekstint) & kluczint)); //xor na bitach intow

    //konwersja dec -> bin
    for (int i = 63; i >= 0; i--) {
        long long int k = resultxor >> i;

        if (i < tekst.size()) { //odp dlugosc napisu
            if (k & 1)
                result += "1";
            else
                result += "0";
        }
    }
    return result;
}
string odszyfruj(string kod, string klucz)// odwrotnosc poprzedniej funkcji ( z main)
{
    return (zaszyfruj(kod, klucz));
}
unsigned char zaszyfruj2(unsigned char kod, unsigned char klucz)//wlasny algorytm: xor z kluczem i rotacja o 1 w lewo
{
    unsigned char result = kod;
    result = zaszyfruj(result, klucz);
    result = (((result << 1)|(result >> 7)));
    return result;
}
unsigned char odszyfruj2(unsigned char kod, unsigned char klucz)//algorytm odkodowania: rotacja o 1 w prawo i xor z kluczem
{
    unsigned char result = kod;
    result = (((result >> 1))|(result << 7));
    result = odszyfruj(result, klucz);
    return result;
}
string przeczytaj(string tekst)//�czyta� tekst o dowolnej dlugosci zlozony z zer i jedynek (z main-a)
{
    string result;
    long long int tekstint = stoi(tekst, nullptr, 2);

    //konwersja dec -> bin
    for (int i = 63; i >= 0; i--) {
        long long int k = tekstint >> i;

        if (i < tekst.size()) { //odp dlugosc
            if (k & 1)
                result += "jeden ";
            else
                result += "zero ";
        }
    }
    return result;
}
//
//int main(int argc, char **argv) {
//    //np: argv[1] = "0100000111", argv[2]= "110001111";
//
//    string string1 = "01000001";
//    cout << "\n" << string1 << " zakodowane:   " << zakoduj(string1) << endl;
//    unsigned char char1 = zakoduj(string1);
//    cout << char1 << " odkodowane:   " << odkoduj(char1) << "\n\n";
//
//
//    unsigned char tekst1 = '#', klucz1 = 'K';
//    cout << tekst1 << " zaszyfrowane xorem:   " << zaszyfruj(tekst1, klucz1) << endl;
//    unsigned char kod1 = zaszyfruj(tekst1, klucz1); //'h'
//    cout << kod1 << " odszyfrowane xorem:   " << odszyfruj(kod1, klucz1) << "\n\n";
//
//
//    cout << argv[1] << " zaszyforwane xorem:   " << zaszyfruj(argv[1], argv[2]) << "\n";
//    string kod2 = zaszyfruj(argv[1], argv[2]);
//    cout << kod2 << " odszyforwane xorem:   " << odszyfruj(argv[1], argv[2]) << "\n\n";
//
//
//    unsigned char tekst3 = '0', klucz3 = '#';
//    cout << tekst3 << " zaszyforwane wlasnym algorytmem:   " << zaszyfruj2(tekst3, klucz3) << endl;
//    unsigned char kod3 = zaszyfruj2(tekst3, klucz3); //'&'
//    cout << kod3 << " odszyforwane wlasnym algorytmem:   " << odszyfruj2(kod3,klucz3) << "\n\n";
//
//    cout << argv[1] << " przeczytane:  " << przeczytaj (argv[1]) << "\n\n\n";
//
//    return 0;
//}
//
//
