//Weronika Zygis
#include "tree.hpp"
#include "branch.hpp"
#include "garden.hpp"

class BRANCH_CLASS;

TREE_CLASS::TREE_CLASS():
        present(true),
        id(0),
        height(0),
        numBranches(0),
        totalNumFruits(0),
        totalWeight(0),
        firstBranch(0),
        lastBranch(0),
        next(0),
        prev(0),
        parentGarden(0) {
}

TREE_CLASS::~TREE_CLASS(){

    BRANCH_CLASS* current = firstBranch;
    while (current!= 0){
        BRANCH_CLASS* nextBranch = current->getNext();
        delete current;
        current = nextBranch;
    }
    firstBranch=0;
    lastBranch =0;
    next = 0;
    prev = 0;

    if (!present) return;
    if (!parentGarden) return;

    parentGarden->setTotalTrees(parentGarden->getTreesTotal()-1);
    parentGarden->setGardenSize(parentGarden->getGardenSize()-1);
}

TREE_CLASS::TREE_CLASS(const TREE_CLASS& other)
{
    present = other.present;
    id = other.id;
    height = 0;
    numBranches =0,
    totalNumFruits =0,
    totalWeight =0,
    next=0;
    prev =0;
    parentGarden =0;

    BRANCH_CLASS* currentOriginal = other.firstBranch;
    BRANCH_CLASS* previousCopied = 0;

    while (currentOriginal != 0) {

        BRANCH_CLASS* copiedBranch = new BRANCH_CLASS(*currentOriginal);
        copiedBranch->setParentTree(this);

        if (previousCopied){
            previousCopied->setNext(copiedBranch);
            copiedBranch->setPrev(previousCopied);
        }
        else firstBranch = copiedBranch;

        previousCopied = copiedBranch;
        currentOriginal = currentOriginal->getNext();
    }
    lastBranch = previousCopied;
}

//------------------getters-----------------------
unsigned int TREE_CLASS::getBranchesTotal() const{
    return numBranches;
}
unsigned int TREE_CLASS::getFruitsTotal() const{
    return totalNumFruits;
}
unsigned int TREE_CLASS::getWeightsTotal() const{
    return totalWeight;
}
unsigned int TREE_CLASS::getNumber() const {
    return id;
}
unsigned int TREE_CLASS::getHeight() const{
    return height;
}
GARDEN_CLASS* TREE_CLASS::getGardenPointer() const{
    return parentGarden;
}
TREE_CLASS* TREE_CLASS::getNext() const{
    return next;
}
TREE_CLASS* TREE_CLASS::getPrev() const{
    return prev;
}
bool TREE_CLASS::getPresent() const{
    return present;
}

BRANCH_CLASS* TREE_CLASS::getBranchPointer(unsigned int h) {
    if (h > getHeight()) return 0;
    BRANCH_CLASS *current = firstBranch;
    while (current != 0) {
        if (current->getPresent()){
            if (current->getHeight() == h) return current;
        }
        current = current->getNext();
    }
    return 0;
}



///-------------------operations---------------------

void TREE_CLASS::growthTree(){

    BRANCH_CLASS* newBranch = new BRANCH_CLASS();
    newBranch->setPresent(false);
    newBranch->setParentTree(this);

    if (firstBranch == 0){
        newBranch->setHeightOnTree(1);
        firstBranch = newBranch;
        lastBranch = newBranch;
        return;
    }

    lastBranch->setNext(newBranch);
    newBranch->setPrev(lastBranch);
    newBranch->setHeightOnTree(lastBranch->getHeight() + 1);
    lastBranch = newBranch;


    BRANCH_CLASS* current = firstBranch;
    while(current!=0){
        if (current->getPresent()) current->growthBranch();
        current = current->getNext();
    }

    if (height%3!=0 || height ==0) return;
    newBranch->setPresent(true);
    numBranches++;

    if (!parentGarden) return;
    parentGarden->setTotalBranches(parentGarden->getBranchesTotal()+1);

}
void TREE_CLASS::fadeTree(){
    if (height == 0) return;
    if (lastBranch == firstBranch){
        delete lastBranch;
        this->setFirstBranch(0);
        this->setLastBranch(0);
        height =0;
        return;
    }

    BRANCH_CLASS* toDelete = lastBranch;
    lastBranch = lastBranch->getPrev();

    if (lastBranch) lastBranch->setNext(0);
    else{
        delete toDelete;
        this->setLastBranch(0);
        this->setFirstBranch(0);
        return;
    }

    BRANCH_CLASS* current = firstBranch;
    while (current) {
        BRANCH_CLASS* nextBranch = current->getNext();
        if (current->getPresent()) {
            if (current->getPresent())current->fadeBranch();
        }
        current = nextBranch;
    }

    delete toDelete;

}
void TREE_CLASS::harvestTree(unsigned w){
    BRANCH_CLASS* current = firstBranch;
    while (current!=0){
        if (current->getPresent()) current->harvestBranch(w);
        current = current->getNext();
    }
}
void TREE_CLASS::cutTree(unsigned h){
    if (h>=height) return;
    if (h==0){
        BRANCH_CLASS* current = firstBranch;
        while (current!=0){
            BRANCH_CLASS* toDelete = current->getNext();
            delete current;
            current = toDelete;
        }
        firstBranch = 0;
        lastBranch =0;
        height =0;
        return;
    }

    BRANCH_CLASS* current = firstBranch;
    while (current!=0 && current->getHeight()!=h){
        current = current->getNext();
    }
    if (current == 0) return;

    current = current->getNext();

    if (current->getPrev()) {
        current->getPrev()->setNext(0);
        lastBranch = current->getPrev();
    }
    else firstBranch = current->getNext();

    while (current!=0){
        BRANCH_CLASS* toDelete = current->getNext();
        delete current;
        current = toDelete;
    }

    height = h;
}
void TREE_CLASS::cloneBranch (BRANCH_CLASS* a) {
    if (a == 0 || numBranches<=0 || !firstBranch) return;

    BRANCH_CLASS * cloned = new BRANCH_CLASS(*a);

    if (!cloned->getPresent()){
        delete cloned;
        return;
    }

    BRANCH_CLASS *current = firstBranch;
    while (current != 0) {
        if (current->getPresent()){
            if (current->getLength()==0) break;
        }
        current = current->getNext();
    }
    if (current == 0) {
        delete cloned;
        return;
    }

    unsigned int h = current->getHeight();


    BRANCH_CLASS* previous = current->getPrev();
    BRANCH_CLASS* following = current->getNext();
    cloned->setHeightOnTree(h);
    cloned->setParentTree(this);
    if (current == firstBranch && current == lastBranch){
        firstBranch = cloned;
        lastBranch = cloned;
        current->setNext(0);
        current->setPrev(0);
        delete current;
        return;
    }
    if (current == firstBranch) {
        firstBranch = cloned;
        cloned->setPrev(0);
    }
    if (current == lastBranch){
        lastBranch = cloned;
        cloned->setNext(0);
    }
    delete current;

    if (following) following->setPrev(cloned);
    if (previous) previous->setNext(cloned);
    cloned->setNext(following);
    cloned->setPrev(previous);

}


//------------setters------------------------

void TREE_CLASS::setNext(TREE_CLASS* nextTree) {
    next = nextTree;
}
void TREE_CLASS::setPrev(TREE_CLASS *pTree) {
    prev = pTree;
}
void TREE_CLASS::setHeight(unsigned h) {
    this->height = h;
}
void TREE_CLASS::setTotalBranches(unsigned nB) {
    this->numBranches = nB;
}
void TREE_CLASS::setTotalFruits(unsigned tF) {
    this->totalNumFruits = tF;
}
void TREE_CLASS::setTotalWeight(unsigned tW) {
    this->totalWeight = tW;
}
void TREE_CLASS::setParentGarden(GARDEN_CLASS* const g){
    this->parentGarden = g;
    parentGarden->setGardenSize(parentGarden->getGardenSize()+1);

    if (!present) return;
    parentGarden->setTotalWeight(parentGarden->getWeightsTotal() + totalWeight);
    parentGarden->setTotalFruits(parentGarden->getFruitsTotal() + totalNumFruits);
    parentGarden->setTotalBranches(parentGarden->getBranchesTotal()+ numBranches);
    parentGarden->setTotalTrees(parentGarden->getTreesTotal()+1);
}
void TREE_CLASS::setPresent(bool a){
    this->present = a;
}
void TREE_CLASS::setFirstBranch(BRANCH_CLASS* a){
    firstBranch = a;
}
void TREE_CLASS::setLastBranch(BRANCH_CLASS* a){
    lastBranch = a;
}
void TREE_CLASS::setNumber(unsigned a){
    this->id = a;
}

void TREE_CLASS::setParent(GARDEN_CLASS *const a) {
    parentGarden = a;
}

