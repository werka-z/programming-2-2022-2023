#include "array3D.h"
#include <iostream>

Tensor::Tensor(){
    printf("podstawowy konstruktor tensora\n");
    tensor = nullptr;
    baseHeight = 0;
    baseWidth = 0;
    depths = nullptr;
}

Tensor::Tensor(int baseHeight, int baseWidth, int* depths_){
    printf("konstruktor tensora inicjalizujacy zerami\n");
    this->baseWidth = baseWidth;
    this->baseHeight = baseHeight;
    //this->depths = depths_;

    depths = new int [baseWidth];
    for (int i=0; i<baseWidth; i++){
        depths[i] = depths_[i];
    }

    tensor = new double**[baseHeight];

    for (int h = 0; h < baseHeight; h++){
        tensor[h] = new double * [baseWidth];
        for (int w =0; w < baseWidth; w++){
            tensor[h][w] = new double [*(depths+w)];
            for (int i=0; i<*(depths+w); i++)
                tensor[h][w][i] = 0;
        }
    }
}

Tensor::Tensor(const Tensor& tens){
    printf("konstuktor kopiujacy tensora\n");
    this->baseWidth = tens.baseWidth;
    this->baseHeight = tens.baseHeight;

    depths = new int [baseWidth];
    for (int i=0; i< baseWidth; i++){
        depths[i] = tens.depths[i];
    }

    tensor = new double ** [baseHeight];

    for (int h = 0; h < baseHeight; h++){
        tensor[h] = new double * [baseWidth];
        for (int w =0; w < baseWidth; w++){
            tensor[h][w] = new double [*(depths+w)];
            for (int i=0; i<*(depths+w); i++)
                tensor[h][w][i] = tens[h][w][i];
        }
    }
}

Tensor& Tensor::operator=(const Tensor& tens){
    printf("operator przypisania tensora\n");
    if (this == &tens) return *this;

    for (int h = 0; h < baseHeight; h++){
        for (int w =0; w < baseWidth; w++){
            delete tensor[h][w];
        }
        delete tensor[h];
    }
    delete tensor;


    this->baseWidth = tens.baseWidth;
    this->baseHeight = tens.baseHeight;

    depths = new int [baseWidth]; //<<<<<<<<<<<<<<<<<<<<<<
    for (int i=0; i<baseWidth; i++){
        depths[i] = tens.depths[i];
    }

    tensor = new double ** [baseHeight];

    for (int h = 0; h < baseHeight; h++){
        tensor[h] = new double * [baseWidth];
        for (int w =0; w < baseWidth; w++){
            tensor[h][w] = new double [*(depths+w)];
            for (int i=0; i<*(depths+w); i++)
                tensor[h][w][i] = tens[h][w][i];
        }
    }
    return *this;
}

Tensor::~Tensor(){
    for (int h = 0; h < baseHeight; h++){
        for (int w =0; w < baseWidth; w++){
            delete tensor[h][w];
        }
        delete tensor[h];
    }
    delete tensor;
}

void Tensor::displayTensor(){
    //wyswietlanie macierzami idac po indeksach od w do basewidth
    std::cout << "----------------------------------------------" << std::endl;
    for (int w=0; w<baseWidth; w++){
        for (int h = 0; h < baseHeight; h++) {
            for (int i=0; i< *(depths+w); i++){
                std::cout << tensor[h][w][i] << " ";
            }
            std::cout << std::endl; //koniec rzedu
        }
        std::cout << std::endl; //koniec jednej macierzy
    }
    std::cout << "----------------------------------------------" << std::endl; //koniec tensora
}
void Tensor::insert(int row, int column, int depth, double element){
    if (row >= baseHeight || row<0 || column>=baseWidth || column<0 || depth<0 || depth>= *(depths+column)) {
        std::cout<< "niepoprawny indeks - nie mozna tam wpisac elementu.\n" << std::endl;
        return;
    }
    tensor[row][column][depth] = element;
}