#include "array2D.h"
#include "array3D.h"
#include <iostream>

int main() {
    printf("arr\n");
    array2D arr = array2D(5, 4);
    arr.displayArray();
    arr.insert(2,3,7);
    arr.insert( 0, 0, 7);
    arr.insert(7, 7, 7);
    arr.insert(3, 1, 7);
    arr.displayArray();

    printf("arr1:\n");
    array2D arr1 = arr;
    arr1.displayArray();

    printf("arr2:\n");
    array2D arr2 = array2D(arr);
    arr2.displayArray();

    //-------------------------

    printf("tensor1:\n");
    Tensor tensor1 = Tensor();

    int depths[5] = {3,5,3};

    Tensor tensor2 = Tensor(4, 3, depths);
    tensor2.displayTensor();

    tensor2.insert(0, 1, 2, 7.7);
    tensor2.insert(3, 2, 5, 7.1);
    tensor2.insert(2, 2, 2, 5.55);
    tensor2.insert(3, 0, 2, 4.3);

    printf("tensor2: \n");
    tensor2.displayTensor();

    printf("tensor1: \n");
    tensor1 = tensor2;
    tensor1.displayTensor();

    printf("tensor3: \n");
    Tensor tensor3 = Tensor(tensor1);
    tensor3.displayTensor();


    return 0;
}
