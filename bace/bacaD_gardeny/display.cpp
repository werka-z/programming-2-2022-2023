#include <cstdio>
//#pragma once
#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"


void GARDEN_CLASS::display() {
    TREE_CLASS* tree ;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int quantity = this->getTreesTotal();

    printf("GARDEN:\n");
    printf("    Size: %u\n", sizeOfGarden);
    printf("    Number of Trees: %u\n", quantity);
    printf("    Number of Branches: %u\n", getBranchesTotal());
    printf("    Number of Fruits: %u\n", (*this).getFruitsTotal());
    printf("    Total Weight: %u\n", (*this).getWeightsTotal());
    printf("    All Trees:\n");

    while (i < quantity) {
        tree = this->getTreePointer(j);
        if (tree != NULL) {
            (*tree).display();
            i += 1;
        }
        j += 1;
    }
    printf("    Successful Display all of %u Trees\n\n", quantity);
}

void TREE_CLASS::display() {
    //GARDEN_CLASS* garden = this->getGardenPointer();
    BRANCH_CLASS* branch;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int quantity = (*this).getBranchesTotal();

    printf(" Tree no %u: ", (*this).getNumber());

    printf("height: %u, ", (*this).getHeight());
    printf("branches: %u, ", quantity);
    printf("fruits: %u, ", this->getFruitsTotal());
    printf("weight: %u.", this->getWeightsTotal());
    printf("branches:\n");

    while (i < quantity) {
        branch = (*this).getBranchPointer(3 * j);
        if (branch != NULL) {
            (*branch).display();
            i += 1;
        }
        j += 1;
    }
   // printf("        Successful Display all of %u Branches\n", quantity);
}

void BRANCH_CLASS::display() {
    //TREE_CLASS* tree = (*this).getTreePointer();
    FRUIT_CLASS* fruit;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int quantity = (*this).getFruitsTotal();

    printf("            Branch at height %u: ", (*this).getHeight());
    printf("length: %u, ", (*this).getLength());
    printf("fruits: %u, ", quantity);
    printf("total weight: %u. ", (*this).getWeightsTotal());
    printf("Its fruits:\n");

    while (i < quantity) {
        fruit = (*this).getFruitPointer(j << 1);
        if (fruit != NULL) {
            (*fruit).display();
            i += 1;
        }
        j += 1;
    }
    //printf("            Successful Display all of %u Fruits\n", quantity);
}

void FRUIT_CLASS::display() {
    printf("                        at length %u, ", (*this).getLength());
    printf("weight: %u \n ", (*this).getWeight());
}
