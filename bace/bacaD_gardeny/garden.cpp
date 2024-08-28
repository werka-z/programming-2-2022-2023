//Weronika Zygis
#include "garden.hpp"
#include "tree.hpp"

GARDEN_CLASS::GARDEN_CLASS() :
        sizeOfGarden(0),
        numTrees(0),
        numBranches(0),
        numFruits(0),
        totalWeight(0),
        firstTree(0),
        lastTree(0),
        lowestFreeID(0){}

GARDEN_CLASS::~GARDEN_CLASS(){

    TREE_CLASS* current = firstTree;
    while (current!= 0) {
        TREE_CLASS* nextTree = current->getNext();
        delete current;
        current = nextTree;
    }

    firstTree = 0;
    lastTree=0;
}
GARDEN_CLASS::GARDEN_CLASS(const GARDEN_CLASS& other){
    sizeOfGarden = other.sizeOfGarden;
    numTrees=0;
    numBranches=0;
    numFruits=0;
    totalWeight=0;
    firstTree=0;
    lastTree=0;
    lowestFreeID = other.lowestFreeID;

    TREE_CLASS *currentOriginal = other.firstTree;
    TREE_CLASS* previousCopied = 0;

    while (currentOriginal != 0) {

        TREE_CLASS *copiedTree = new TREE_CLASS(*currentOriginal);
        copiedTree->setParentGarden(this);

        if (previousCopied!=0){
            previousCopied->setNext(copiedTree);
            copiedTree->setPrev(previousCopied);
        }
        else firstTree = copiedTree;

        previousCopied = copiedTree;
        currentOriginal = currentOriginal->getNext();
    }
    lastTree = previousCopied;
}


//-----------------------getters----------------------
unsigned int GARDEN_CLASS::getTreesTotal() const{
    return numTrees;
}
unsigned int GARDEN_CLASS::getBranchesTotal()const{
    return numBranches;
}
unsigned int GARDEN_CLASS::getFruitsTotal()const{
    return numFruits;
}
unsigned int GARDEN_CLASS::getWeightsTotal()const{
    return totalWeight;
}



void GARDEN_CLASS::plantTree() {
    if (!firstTree){
        TREE_CLASS* newTree = new TREE_CLASS();
        firstTree = newTree;
        lastTree = newTree;
        lastTree->setNumber(0);
        lastTree->setParentGarden(this);
        firstTree = lastTree;
        return;
    }

    //2. nie ma luk
    if (numTrees == lastTree->getNumber()+1){
        TREE_CLASS* newTree = new TREE_CLASS();
        unsigned number = lastTree->getNumber()+1;
        newTree->setPrev(lastTree);
        lastTree->setNext(newTree);
        lastTree = newTree;
        lastTree->setNumber(number);
        lastTree->setParentGarden(this);
        return;
    }
    //sa luki
    TREE_CLASS* current = lastTree;
    while (current!=0){
        if (!current->getPresent()) break;
        current = current->getPrev();
    }
    current->setPresent(true);
    numTrees++;
}



void GARDEN_CLASS::extractTree(unsigned id) {
    if (id >= sizeOfGarden) return;
    TREE_CLASS* toExtract = lastTree;
    while (toExtract != 0) {
        if (toExtract->getNumber() == id){
            if (toExtract->getPresent()) break;
            else return;
        }
        toExtract = toExtract->getPrev();
    }
    if (!toExtract)return ;

    TREE_CLASS* replacement = new TREE_CLASS();
    replacement->setPresent(false);
    replacement->setNumber(id);
    replacement->setParent(this);
    sizeOfGarden +=1;



    TREE_CLASS* previous = toExtract->getPrev();
    TREE_CLASS* following = toExtract->getNext();

    if (toExtract == lastTree && toExtract!= firstTree){
        previous->setNext(replacement);
        replacement->setPrev(previous);
        toExtract->setNext(0);
        toExtract->setPrev(0);
        delete toExtract;
        lastTree = replacement;
        return;
    }
    if (lastTree == toExtract && firstTree == toExtract){
        toExtract->setNext(0);
        toExtract->setPrev(0);
        delete toExtract;
        firstTree = replacement;
        lastTree = replacement;
        return;
    }
    if (toExtract == firstTree){
        toExtract->setNext(0);
        toExtract->setPrev(0);
        delete toExtract;
        following->setPrev(replacement);
        replacement->setNext(following);
        firstTree = replacement;
        return;
    }

    toExtract->setNext(0);
    toExtract->setPrev(0);

    delete toExtract;

    following->setPrev(replacement);
    replacement->setNext(following);
    previous->setNext(replacement);
    replacement->setPrev(previous);

}
void GARDEN_CLASS::growthGarden(){
    TREE_CLASS* current = firstTree;
    while (current!=0){
        if (current->getPresent()) current->growthTree();
        current = current->getNext();
    }
}
void GARDEN_CLASS::fadeGarden(){
    TREE_CLASS* current = firstTree;
    while (current!=0){
        if (current->getPresent())current->fadeTree();
        current = current->getNext();
    }
}
void GARDEN_CLASS::harvestGarden(unsigned int weight){
    TREE_CLASS* current = firstTree;
    while (current!=0){
        if (current->getPresent() && current->getWeightsTotal() >= weight) current->harvestTree(weight);
        current = current->getNext();
    }
}
TREE_CLASS* GARDEN_CLASS::getTreePointer(unsigned int id){
    if (id >= sizeOfGarden) return 0;
    //cout << " getTreePointer\n";

    if (id > sizeOfGarden-id) {
        TREE_CLASS *current = lastTree;
        while (current != 0) {
            if (current->getPresent()) {
                if (current->getNumber() == id) return current;
            }
            current = current->getPrev();
        }
        return 0;
    }
    TREE_CLASS *current = firstTree;
    while (current != 0) {
        if (current->getPresent()) {
            if (current->getNumber() == id) return current;
        }
        current = current->getNext();
    }
    return 0;
}
void GARDEN_CLASS::cloneTree(unsigned int a){
    if (a > sizeOfGarden || getTreePointer(a) == 0 || firstTree ==0){
        return;
    }

    TREE_CLASS* newTree = new TREE_CLASS(*getTreePointer(a));

    if (!newTree->getPresent()) {
        delete newTree;
        return;
    }

    //nie ma luk
    if (sizeOfGarden == numTrees){
        if (!firstTree) {
            newTree->setNumber(0);
            newTree->setPresent(true);
            newTree->setParentGarden(this);
            firstTree = newTree;
            lastTree = newTree;
            //cout << "cloneTree returning: gardensize: " << sizeOfGarden << " numTrees: " << numTrees << ", created a new tree with number " << number <<"\n\n";
            return;
        }
        else{
            unsigned number = lastTree->getNumber()+1;
            newTree->setPrev(lastTree);
            lastTree->setNext(newTree);
            newTree->setNumber(number);
            newTree->setParentGarden(this);
            lastTree = newTree;
//            cout << "cloneTree returning: gardensize: " << sizeOfGarden << " numTrees: " << numTrees <<
//             ", created a new tree with number " << number <<"\n\n";
            return;
        }
    }
//    printf(" Lasttree %d, sizeofGarden %d, numtrees %d.\n", lastTree->getNumber(), sizeOfGarden, numTrees);

    //sa luki
    TREE_CLASS* current = firstTree;
    while (current!=0){
        if (!current->getPresent()) break;
        current = current->getNext();
    }

    unsigned number = current->getNumber();
    //cout << "\na spot found at number " << number << " current is present " << current->getPresent() << endl;

    TREE_CLASS* previous = current->getPrev();
    TREE_CLASS* following = current->getNext();

    newTree->setNumber(number);
    newTree->setParentGarden(this);

    if (current == firstTree) firstTree = newTree;
    if (current == lastTree) lastTree = newTree;

    delete current;

    if (previous) previous->setNext(newTree);
    if (following) following->setPrev(newTree);

    newTree->setNext(following);
    newTree->setPrev(previous);

}




//---------------------setters--------------------

void GARDEN_CLASS::setTotalTrees(unsigned num) {
    numTrees = num;
}
void GARDEN_CLASS::setTotalBranches(unsigned num) {
    numBranches = num;
}
void GARDEN_CLASS::setTotalFruits(unsigned num) {
    numFruits = num;
}
void GARDEN_CLASS::setTotalWeight(unsigned weight) {
    totalWeight = weight;
}
void GARDEN_CLASS::setFirstTree(TREE_CLASS* tree) {
    firstTree = tree;
}
void GARDEN_CLASS::setLastTree(TREE_CLASS* tree) {
    lastTree = tree;
}


void GARDEN_CLASS::setGardenSize(unsigned s){
    sizeOfGarden = s;
}
unsigned GARDEN_CLASS::getGardenSize() const{
    return sizeOfGarden;
}

void GARDEN_CLASS::setLowestFreeID (unsigned x){
    lowestFreeID = x;
}
unsigned GARDEN_CLASS::getLowestFreeID(){
    return lowestFreeID;
}