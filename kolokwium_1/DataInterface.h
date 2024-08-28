#ifndef KOLOKWIUM1_DATAINTERFACE_H
#define KOLOKWIUM1_DATAINTERFACE_H
#include "Table.h"

class DataInterface {
public:
    Table table;
    int counter;

    void start();
    void scan(int i);
    void save(int i);
};



#endif //KOLOKWIUM1_DATAINTERFACE_H
