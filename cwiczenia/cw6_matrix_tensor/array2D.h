#ifndef ZAJECIA6_ARRAY2D_H
#define ZAJECIA6_ARRAY2D_H


class array2D {
    double** array;
    int* rowLengths;
    int height;

public:

    array2D();
    array2D(int Height, int rowsLength);
    array2D(const array2D& arr);
    array2D& operator=(const array2D& arr);
    ~array2D();
    void displayArray();
    void insert(int row, int column, double element);

};


#endif
