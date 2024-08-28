#include <iostream>
using namespace std;


//-------------va_lista--------------

#include <cstdarg>
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
//#include <cstdarg>
#include <fstream>

void rozdzielNaHex (string inputFile, int outputCount, string outputFile1, ...)
{//rozdziela input na wyjściowe pliki z flagami hex i uppercase

    //utworzenie i otwarcie strumieni, ustawienie listy [...]
    va_list ap;
    va_start(ap, outputFile1); //lista ustawiona na ostatni arg

    ofstream *output = new ofstream[outputCount]; //tablica ofstreamów
    output[0].open(outputFile1);
    for (int i=1; i < outputCount; i++){
        output[i].open(va_arg(ap, char*));
    }
    va_end(ap);
    ifstream input(inputFile);


    ios::fmtflags flagi = cout.flags(); //bierzemy ustawienia z cout'a
    cout.unsetf(ios::dec);      //unset defaultowa flage
    cout.setf(ios::uppercase | ios::hex);


    //przepisywanie
    int k=0;
    string line;
    while (getline(input, line)){
        int lineint = stoi(line);
        output[k].copyfmt(cout); //na dany stream
        output[k] << lineint << endl;
        k = (k+1) % outputCount;
    }

    //zamkniecie strumieni, cofniecie flag, zwolnienie pamieci
    for (int i=0; i < outputCount; i++){
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

//#include <cstdio>
int blueImage(){
    const char* input = "../krakow.bmp";
    //const char* input = "../wmii.bmp";
    const char* output = "../output.bmp";

    FILE* inputFile = fopen(input, "rb"); //<-read binary

    if (!inputFile){
        cerr << "nie moge otworzyc inputu" << endl;
        return 1;
    }

    unsigned char headers[54]; // bmp header - 14 bitow, dib header 40 bitow
    fread(headers, 1, 54, inputFile); //czyta do headers headersy

    int width = *(int*)&headers[18]; //w tych bajtach jest info o width (int) i height (int)
    int height = *(int*)&headers[22];

    int rowSizeBits = (24*width + 31)/32; //bity w rzedzie + 31/32 (zaokraglenie do intow)
    int rowSizeBytes = rowSizeBits*4;
    int imageSize = rowSizeBytes * abs(height); //abs bo czasami czyta od dolu do gory

    auto *imageData = new unsigned char[imageSize]; //<- tablica dlugosci ilosci bitow calego zdjecia

    //czytanie z inputu do imageData
    fread(imageData, imageSize, 1, inputFile);
    fclose(inputFile);

    for (int y = 0; y < height; y++) {    //podmianka kolorów
        for (int x = 0; x < width; x++) {
            int i = y * rowSizeBytes + x * 3;
            imageData[i] = 255;
            //imageData[i+1] = 0;//<- wersja bez zieleni
            //imageData[i+2] = 0;//<- wersja niebiesko-zielona
        }
    }
    FILE* outputFile = fopen(output, "wb");

    if (!outputFile){
        cerr << "nie moge otworzyc outputu" << endl;
        delete[] imageData;
        return 1;
    }

    //wczytanie headersow i calego obrazka do outputu
    fwrite(headers, 1, 54, outputFile);
    fwrite(imageData, imageSize, 1, outputFile);
    fclose(outputFile);

    delete[] imageData;
    cout << "sukces! sprawdz output" << endl;
    return 0;
}

class DyskTw{
    int pojemnosc;
    float RPM;

public:
    DyskTw() : pojemnosc(512), RPM(0){
        cout << "konstruktor domyslny klasy dyskTw - lista inicjalizacyjna" << endl;
    }

    DyskTw(int pojemnosc_, float RPM_ = 0.7){
        cout << "argumenty domyslne - konstruktor klasy dyskTw" << endl;
        pojemnosc = pojemnosc_;
        RPM = RPM_;
    }

    void usunieciePlikow(int gb){
        cout << "zaplenienie " << gb << " GB pamieci" << endl;
        pojemnosc += gb;
    }

};
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
};
class Komputer {
    Procesor procesor;
    DyskTw dyskTw;

public:
    Komputer() : procesor(), dyskTw(){
        cout << "konstruktor domyslny klasy komputer - z konstruktorami skladowych" << endl;
    }

    Komputer(Procesor p, DyskTw d) : procesor(p), dyskTw(d){
        cout << "konstruktor Komputera - z konstruktorami skladowych" << endl;
    }

    void podmienProcesor(const Procesor &p){
        cout << "podmianka procesora" << endl;
        procesor = p;
    }

    void zwolnieniePamieci(int gb){
        cout << "zapis do pamieci z klasy Komputer" << endl;
        dyskTw.usunieciePlikow(gb);
    }
};


class MyString{
    int ID;
    char** sentences;
    int* senLengths;
    int numSentences;

public:
    MyString(): sentences(nullptr), ID(0), numSentences(0){
        cout << "konstruktor domyslny";
    }

    MyString(int id, int numS, int sLengths): ID(id){

        numSentences = numS;
        senLengths = new int [numSentences];
        sentences = new char *[numSentences];

        for (int i=0; i< numSentences; i++){
            senLengths[i] = sLengths;
            sentences[i] = new char[sLengths];
            for (int j=0; j<senLengths[i]; j++){
                sentences[i][j] = '0';
            }
        }
    }

    ~MyString(){

        for (int i=0; i < numSentences; i++){
            delete[] sentences[i];
        }

        delete[] senLengths;
        delete[] sentences;
    }

    MyString(const MyString& myString){

        ID = myString.ID;

        numSentences = myString.numSentences;
        senLengths = new int [numSentences];
        sentences = new char *[numSentences];

        for (int i=0; i< numSentences; i++){
            senLengths[i] = myString.senLengths[i];
            sentences[i] = new char[senLengths[i]];
            for (int j=0; j<senLengths[i]; j++){
                sentences[i][j] = myString.sentences[i][j];
            }
        }
    }

    MyString& operator=(const MyString& myString){
        if (this == &myString) return *this; //<<<<<<<<<<<<<<

        for (int i=0; i < numSentences; i++){
            delete[] sentences[i];
        }

        delete[] senLengths;
        delete[] sentences;

        ID = myString.ID;
        numSentences = myString.numSentences;

        //memcpy (dest*, (const) src*, size)

        senLengths = new int [numSentences];
        memcpy(senLengths, myString.senLengths, numSentences*sizeof (int));
        sentences = new char *[numSentences];

        for (int i=0; i< numSentences; i++){
            senLengths[i] = myString.senLengths[i];
            sentences[i] = new char[senLengths[i]];
            memcpy(sentences[i], myString.sentences[i], senLengths[i] * sizeof (char));
            //jesli np klasy to  strings[i] = other.strings[i] (uzycie ich operatora przypisania)
        }

        return *this; //<<<<<<<<<<<<<<<
    }

    void insertSentence(char ** sen, int senLen, int idx){

    }
};

class dyplomUJ {
    //static - wszystkie instancje tej klasy, deklaracja poza klasą (zmiana dotyka wszystkie)
    //const - niezmiennik - musi być zainicjalizowany w konstruktorze

    const string nazwisko;
    static int rocznik;
    static const string uczelnia;

public:
    dyplomUJ():  nazwisko(){}

    dyplomUJ (string _nazwisko, int _rocznik) : nazwisko(_nazwisko){
        rocznik = _rocznik;
    }

    void wyswietl() const{
        printf("Absolwent %s na uczelni %s\n", nazwisko.c_str(), uczelnia.c_str());
        printf("Rocznik: %d.\n", rocznik);
    }

};

int dyplomUJ::rocznik = 2020;
const string dyplomUJ::uczelnia = "UJ";


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
