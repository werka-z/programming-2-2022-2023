//Weronika Zygis
#include "fruit.hpp"
#include "branch.hpp"
#include "tree.hpp"
#include "garden.hpp"


BRANCH_CLASS::BRANCH_CLASS(){
    present = true;
    length = 0;
    numFruits = 0;
    totalWeight = 0;
    firstFruit = 0;
    lastFruit = 0;
    heightOnTree = 0;
    parentTree = 0;
    prev = 0;
    next = 0;
}
BRANCH_CLASS::~BRANCH_CLASS(){


    FRUIT_CLASS* current = firstFruit;
    while (current!= 0){
        FRUIT_CLASS* nextFruit = current->getNext();
        delete current;
        current = nextFruit;
    }
    firstFruit = 0;
    lastFruit =0;
    next = 0;
    prev = 0;

    if (!parentTree) return;
    parentTree->setHeight(parentTree->getHeight()-1);

    if (!present) return;

    parentTree->setTotalBranches(parentTree->getBranchesTotal()-1);

    GARDEN_CLASS* parentGarden =parentTree->getGardenPointer();
    if (!parentGarden) return;
    parentGarden->setTotalBranches(parentGarden->getBranchesTotal()-1);
}
BRANCH_CLASS::BRANCH_CLASS (const BRANCH_CLASS& other){
    length = 0;
    numFruits = 0;
    totalWeight = 0;
    present = other.present;
    heightOnTree = other.heightOnTree;
    prev = 0;
    next = 0;
    parentTree = 0;

    FRUIT_CLASS* currentOriginal = other.firstFruit;
    FRUIT_CLASS* previousCopied = 0;

    while (currentOriginal != 0) {
        FRUIT_CLASS* copiedFruit = new FRUIT_CLASS(*currentOriginal);
        copiedFruit->setParentBranch(this);

        if (previousCopied != 0) {
            previousCopied->setNext(copiedFruit);
            copiedFruit->setPrev(previousCopied);
        }
        else firstFruit = copiedFruit;

        previousCopied = copiedFruit;
        currentOriginal = currentOriginal->getNext();
    }

    lastFruit = previousCopied;

}

//----------------getters----------------------
unsigned int BRANCH_CLASS::getFruitsTotal() const{
    return numFruits;
}
unsigned int BRANCH_CLASS::getWeightsTotal() const{
    return totalWeight;
}
unsigned int BRANCH_CLASS::getHeight() const{
    return heightOnTree;
}
unsigned int BRANCH_CLASS::getLength() const{
    return length;
}
TREE_CLASS* BRANCH_CLASS::getTreePointer(){
    return parentTree;
}
BRANCH_CLASS* BRANCH_CLASS::getNext() const {
    return next;
}
BRANCH_CLASS* BRANCH_CLASS::getPrev() const {
    return prev;
}

//----------------------operations---------------------
void BRANCH_CLASS::growthBranch(){

    FRUIT_CLASS* newFruit = new FRUIT_CLASS();
    newFruit->setPresent(false);
    newFruit->setParentBranch(this);

    if (firstFruit == 0){
        newFruit->setLength(1);
        firstFruit = newFruit;
        lastFruit = newFruit;
        return;
    }

    lastFruit->setNext(newFruit);
    newFruit->setPrev(lastFruit);
    newFruit->setLength(lastFruit->getLength()+1);
    lastFruit = newFruit;

    FRUIT_CLASS* current = firstFruit;
    while (current!=0){
        if (current->getPresent()) current->growthFruit();
        current = current->getNext();
    }

    if (length%2!=0 || length ==0) return;

    newFruit->setPresent(true);
    numFruits++;

    if (!parentTree) return;
    parentTree->setTotalFruits(parentTree->getFruitsTotal()+1);
    GARDEN_CLASS* parentGarden = parentTree->getGardenPointer();
    if (!parentGarden) return;
    parentGarden->setTotalFruits(parentGarden->getFruitsTotal()+1);

}
void BRANCH_CLASS::fadeBranch(){
    if (length == 0) return;
    if (lastFruit == firstFruit){
        delete lastFruit;
        this->setFirstFruit(0);
        this->setLastFruit(0);
        return;
    }

    FRUIT_CLASS* toDelete = lastFruit;
    lastFruit = toDelete->getPrev();
    lastFruit->setNext(0);

    FRUIT_CLASS* current = firstFruit;
    while (current) {
        FRUIT_CLASS* nextFruit = current->getNext();
        if (current->getPresent())current->fadeFruit();
        current = nextFruit;
    }

    toDelete->setNext(0);
    toDelete->setPrev(0);
    delete toDelete;

}
void BRANCH_CLASS::harvestBranch(unsigned int weight){

    FRUIT_CLASS* current = firstFruit;
    while (current!= 0){
        if (current->getPresent()){
            if (current->getWeight()>= weight) current->pluckFruit();
        }
        current = current->getNext();
    }
}
void BRANCH_CLASS::cutBranch (unsigned int l){
    if (l>=length) return;
    if (l ==0){
        FRUIT_CLASS* current = firstFruit;
        while (current !=0){
            FRUIT_CLASS* toDelete = current->getNext();
            delete current;
            current = toDelete;
        }
        firstFruit = 0;
        lastFruit = 0;
        length =0;
        return;
    }

    FRUIT_CLASS* current = firstFruit;
    while (current !=0 && current->getLength()!=l){
        current = current->getNext();
    }
    if (current == 0) return;

    current = current->getNext();

    if (current->getPrev()) {
        current->getPrev()->setNext(0);
        lastFruit = current->getPrev();
    }
    else firstFruit = current->getNext();

    while (current!= 0){
        FRUIT_CLASS* toDelete = current->getNext();
        delete current;
        current = toDelete;
    }

    //length = l;
}
FRUIT_CLASS* BRANCH_CLASS::getFruitPointer(unsigned int a){
    if (a>getLength()) return 0;
    FRUIT_CLASS* current = firstFruit;
    while (current!=0){
        if (current->getPresent()){
            if (current->getLength() == a) return current;
        }
        current = current->getNext();
    }
    return 0;
}



//------------------setters-------------
void BRANCH_CLASS::setLength(unsigned l) {
    this->length = l;
}
void BRANCH_CLASS::setTotalFruits(unsigned nf) {
    this->numFruits = nf;
}
void BRANCH_CLASS::setTotalWeight(unsigned tW) {
    this->totalWeight = tW;
}
void BRANCH_CLASS::setHeightOnTree(unsigned int h) {
    this->heightOnTree = h;
}
void BRANCH_CLASS::setFirstFruit(FRUIT_CLASS* fF) {
    this->firstFruit = fF;
}
void BRANCH_CLASS::setLastFruit(FRUIT_CLASS* lF) {
    this->lastFruit = lF;
}
void BRANCH_CLASS::setPrev(BRANCH_CLASS* p) {
    this->prev = p;
}
void BRANCH_CLASS::setNext(BRANCH_CLASS* n) {
    this->next = n;
}
void BRANCH_CLASS::setParentTree(TREE_CLASS* parTree) {
    parentTree = parTree;
    parentTree->setHeight(parentTree->getHeight() + 1);

    if (!present) return;
    parentTree->setTotalWeight(parTree->getWeightsTotal() + getWeightsTotal());
    parentTree->setTotalFruits(parTree->getFruitsTotal() + getFruitsTotal());
    parentTree->setTotalBranches(parentTree->getBranchesTotal() + 1);

    GARDEN_CLASS* parentGarden = parTree->getGardenPointer();
    if (!parentGarden) return;
    parentGarden->setTotalWeight(parTree->getWeightsTotal()+getWeightsTotal());
    parentGarden->setTotalFruits(parTree->getFruitsTotal()+getFruitsTotal());
    parentGarden->setTotalBranches(parentGarden->getBranchesTotal()+1);
}
void BRANCH_CLASS::setPresent(bool a) {
    this->present = a;
}

bool BRANCH_CLASS::getPresent() const{
    return present;
}


