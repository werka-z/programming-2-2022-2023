#include <cstdio>
#include <iostream>
using namespace std;

int main() {

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
    //podmianka kolorów
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int i = y * rowSizeBytes + x * 3;
            imageData[i] = 255;
            //imageData[i+1] = 0;//<- wersja bez zieleni
            //imageData[i+2] = 0;//<- wersja niebiesko-zielona
        }
    }
    //obsluga problemow z outputem
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


