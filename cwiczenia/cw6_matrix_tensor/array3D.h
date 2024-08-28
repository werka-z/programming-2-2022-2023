#ifndef ZAJECIA6_ARRAY3D_H
#define ZAJECIA6_ARRAY3D_H


class Tensor {

    double*** tensor;
    int baseHeight;
    int baseWidth;
    int* depths;


public:

    Tensor();
    Tensor(int baseHeight, int baseWidth, int* depths);
    ~Tensor();
    Tensor (const Tensor& );
    Tensor& operator=(const Tensor&);
    void displayTensor();
    void insert(int row, int column, int depth, double element);
    const double* const* operator[](int index) const {
        return tensor[index];
    }
    double** operator[](int index) {
        return tensor[index];
    }
};


#endif
