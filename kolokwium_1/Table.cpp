#include "Table.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>

/*
 * zmiany:
 * 1. konstruktory i, operator przypisania miały malloc(a * sizeof(char)) zamiast malloc(a * sizeof(char*)) dla rzędów
 * 2. operator przypisania: miał zwalnianie pamięci przed przypisaniem i używał new/delete zamiast malloc/free
 * 3. usuniecie operatora [] - używanie table.table[][]
 * 4. 2 warunki nie były uwzględniane w liczeniu sąsiadów
*/


Table::Table(){
    size =0;
    table = nullptr;
}

Table::Table(int size_){
    size = size_;

    table = (char**) malloc(size *sizeof (char*)); //TODO - zmiana z sizeof(char) na (char*)
    //table = new char* [size];

    for (int i=0; i<size; i++){
        table[i] = (char*) malloc(size * sizeof(char));
        //table[i] = new char [size];
        for (int j=0; j<size; j++){
            table[i][j] = '_';
        }
    }
}

Table::Table(const Table& table_){

    size = table_.size;
    table = (char**) malloc(size*sizeof (char*)); //TODO zmiana z (char) na (char*)
    //table = new char * [size];

    for (int i=0; i<size; i++){
        table[i] = (char*)malloc(size*sizeof (char));
        //table[i] = new char [size];
        memcpy(table[i], table_.table[i], size * sizeof (char));
    }
}

Table& Table::operator=(const Table& table_){
    if (this == &table_) return *this;

    char** newTable = (char**)malloc(table_.size * sizeof (char*));
    //char** newTable = new char *[table_.size];
    for (int i=0; i<table_.size; i++){
        newTable[i] = (char*)malloc(table_.size * sizeof (char));
        //newTable[i] = new char [table_.size];
        memcpy(newTable[i], table_.table[i], table_.size * sizeof (char));
    }
    for (int i=0; i<size; i++){
        free(table[i]);
        //delete[] table[i];
    }
    free(table);
    //delete[] table;

    table = newTable;
    size = table_.size;
    return *this;
}

//Table& Table::operator=(const Table& table_){
//    if (this == &table_) return *this;
//
//
//    for (int i=0; i<size; i++){
//        delete[] table[i];
//    }
//
//    size = table_.size;
//    delete table;
//
//    table = new char * [size];
//    for (int i=0; i<size; i++){
//        table[i] = new char [size];
//        memcpy(table[i], table_.table[i], size * sizeof (char));
//    }
//    return *this;
//}

Table::~Table(){
    for (int i=0; i<size; i++){
        free(table[i]);
    }

    free(table);
}

void Table::display(){
    //bez paddingu
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            if (i==0 || i == size-1 || j ==0 || j == size -1);
            else printf("%c", table[i][j]);
        }
        printf("\n");
    }
}

int Table::neighbors(int I, int J) {
    int counter =0;
    if (I == 0 || J==0 || I == size-1 || J == size-1) return 0;

    if (table[I-1][J-1] == 'X') counter ++;
    if (table[I-1][J+1] == 'X')counter ++;
    if (table[I-1][J]== 'X') counter++;

    if (table[I][J-1]=='X') counter ++;
    if (table[I][J+1] == 'X') counter ++;

    if (table[I+1][J-1] == 'X') counter ++;
    if (table[I+1][J+1] == 'X')counter ++;
    if (table[I+1][J] == 'X') counter ++;
    return counter;
//    if (I>0){
//        if (J>0){
//            if (table[I-1][J-1] == 'X') counter ++;
//            if (table[I][J-1]=='X') counter ++;
//        }
//        if (J<size-1){
//            if (table[I-1][J+1] == 'X')counter ++;
//            if (table[I][J+1] == 'X') counter ++;
//        }
//    }
//    if (I<size-1){
//        if (J>0){
//            if (table[I+1][J-1] == 'X') counter ++;
//            if (table[I][J-1] == 'X') counter ++;
//
//        }
//        if (J<size-1){
//            if (table[I+1][J+1] == 'X')counter ++;
//            if (table[I][J+1] == 'X') counter ++;
//        }
//    }

}

void Table::set(char c, int i, int j){
    table[i][j] = c;
}