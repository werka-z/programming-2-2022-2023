#include "DataInterface.h"
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

/*todo zmiany:
 * 1. wczytywanie: odczytanie rozmiaru tablicy, poprawne pomijanie '\n'
 * 2. zapisywanie do plików zamiast wyświetlania na stdout
*/

void DataInterface::start() {
    printf("Witaj w grze o zycie! Wpisz liczbe krokow, ktora chcesz wykonac\n");
    int c;
    scanf("%d", &c);
    counter = c;
}

void DataInterface::scan(int k){

    string name = "../tablica_" + to_string(k) + ".txt";
    const char* input = name.c_str();

    FILE* inputFile = fopen(input, "r");

    if (!inputFile) {
        perror("nie moge otworzyc inputu\n");
        return;
    }

    //rozpoznanie rozmiaru
    int rows = 0, cols = 0;
    char ch;
    char lastChar = '\0';
    while ((ch = fgetc(inputFile)) != EOF){
        if (rows == 0 && ch != '\n') cols++;
        if (ch == '\n') {
            rows++;
        }
        lastChar = ch;
    }
    if (lastChar != '\n') rows++;

    if (cols != rows){
        cout << "rows:" << rows << "cols:" << cols << endl;
        perror("niepoprawny rozmiar tablicy\n");
        return;
    }

    table = Table(rows+2);
    fseek(inputFile, 0, SEEK_SET); //powrot na poczatek

    for (int i = 1; i < table.size - 1; i++) {
        for (int j = 1; j < table.size - 1; j++) {
            do {
                ch = fgetc(inputFile);
            } while (ch == '\n');

            if (ch == 'X' || ch == '_') {
                table.table[i][j] = ch;
            }
        }
    }
    fclose(inputFile);

}

void DataInterface::save(int k) {

    string name = "../tablica_" + to_string(k) + ".txt";
    const char* output = name.c_str();

    FILE* outputFile = fopen(output, "w");

    if (!outputFile){
        perror("nie moge otworzyc outputu\n");
        return;
    }

    for (int i=1; i<table.size-1; i++){
        for (int j=1; j<table.size-1; j++){
            fputc(table.table[i][j], outputFile);
        }
        fputc('\n', outputFile);
    }

    fclose(outputFile);
}