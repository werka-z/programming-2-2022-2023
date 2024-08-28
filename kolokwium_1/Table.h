#ifndef KOLOKWIUM1_TABLE_H
#define KOLOKWIUM1_TABLE_H


class Table {
    char** table;
public:

    int size;
    Table();
    Table(int size_);
    Table(const Table& table_);
    Table& operator=(const Table& Table);
    ~Table();
    void display();
    void set(char c, int i, int j);
    int neighbors(int , int);
    //const char* operator[] (int index) const {return table[index];}

    friend class DataInterface;
    friend class Game;
};


#endif //KOLOKWIUM1_TABLE_H
