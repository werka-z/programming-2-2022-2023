#include "Game.h"
#include "Table.h"


void Game::step(){
    Table newTable = Table(data.table); //konstruktor kopiujacy

    //zmiana tablicy
    for (int i=1; i<newTable.size-1; i++){
        for (int j=1; j< newTable.size-1; j++){
            int neighbors = data.table.neighbors(i,j);
            if (newTable.table[i][j] == 'X'){
                if (neighbors != 3 && neighbors != 2)
                    newTable.set('_', i, j);
            }
            else if (newTable.table[i][j] == '_'){
                if (neighbors == 3)
                    newTable.set('X', i, j);
            }
        }
    }
    //operator przypisania
    data.table = newTable;
}

void Game::play(){

    data.start();
    for (int i=1; i<=data.counter; i++){
        data.scan(i);
        //cout << "Krok " << i << ":" << endl;
        //data.table.display();
        //cout << "-----------------------------------" << endl;
        step();
        data.save(i+1);
    }
}