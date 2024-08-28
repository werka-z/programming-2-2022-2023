#ifndef KOLOKWIUM1_GAME_H
#define KOLOKWIUM1_GAME_H
#include "DataInterface.h"

class Game {
    DataInterface data;

public:
    void step();
    void play();
};


#endif //KOLOKWIUM1_GAME_H
