#include "array2D.h"
#include <iostream>
using namespace std;

array2D::array2D(){
    printf("podstawowy konstruktor array2D\n");
    array = nullptr;
    rowLengths = nullptr;
    height = 0;
}

array2D::array2D(int Height, int lengths){
    printf("konstruktor array2D inicjalizujacy zerami\n");
    height = Height;

    rowLengths = new int[height];
    array = new double * [height];

    for (int i=0; i<height; i++){

        *(rowLengths+i) = lengths;
        *(array+i) = new double [lengths];
        for (int j=0; j<rowLengths[i]; j++){
            array[i][j] = 0;
        }
    }
}

array2D::array2D(const array2D& arr){
    cout << "konstruktor kopiujacy\n";
    height = arr.height;

    rowLengths = new int[height];
    memcpy(rowLengths, arr.rowLengths, height * sizeof(int));

    array = new double *[height];
    for (int i = 0; i < height; i++) {
        rowLengths[i] = arr.rowLengths[i];
        array[i] = new double[rowLengths[i]];
        memcpy(array[i], arr.array[i], rowLengths[i] * sizeof(double));
    }
}

array2D& array2D::operator=(const array2D& arr) {
    cout << "operator przypisania\n";
    if (this == &arr) return *this;

    for (int i = 0; i < height; i++) {
        delete[] array[i];
    }
    delete[] array;
    delete[] rowLengths;

    height = arr.height;

    rowLengths = new int[height];
    memcpy(rowLengths, arr.rowLengths, height * sizeof(int));
    array = new double *[height];

    for (int i = 0; i < height; i++) {
        rowLengths[i] = arr.rowLengths[i];
        array[i] = new double[rowLengths[i]];
        memcpy(array[i], arr.array[i], rowLengths[i] * sizeof(double));
    }

    return *this;
}

array2D::~array2D(){
    for (int i=0; i<height; i++){
        delete[] array[i];
    }
    delete[] array;
    delete[] rowLengths;
}

void array2D::displayArray(){
    std::cout << "----------------------------------------------" << std::endl;
    for (int i=0; i<height; i++){
        for (int j=0; j<*(rowLengths+i); j++){
            std::cout << *(*(array+i)+j) << " ";
        }
        std::cout<< std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;
}

void array2D::insert(int row, int column, double element){
    if (row<0 || column <0 || row>height || column >rowLengths[row]) {
        cout << "niepoprawne wspolrzedne - nie mozna tam wpisac elementu\n";
        return;
    }
    array[row][column] = element;
}