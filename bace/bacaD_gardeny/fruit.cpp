//Weronika Zygis
#include "fruit.hpp"
#include "branch.hpp"
#include "tree.hpp"
#include "garden.hpp"

//--------------------con/destructors
FRUIT_CLASS::FRUIT_CLASS(){
    present = true;
    next = 0;
    prev = 0;
    weight = 0;
    positionInBranch = 0;
    parentBranch = 0;
}
FRUIT_CLASS::~FRUIT_CLASS(){

    if (parentBranch!=0){
        if (parentBranch->getLength() > 0) parentBranch->setLength(parentBranch->getLength()-1);
    }

    if (prev!=0) prev->next = next;
    if (next!=0) next->prev = prev;
    next = 0;
    prev =0;

    if (!present) return;

    if (!parentBranch) return;
    parentBranch->setTotalWeight(parentBranch->getWeightsTotal() - weight);
    parentBranch->setTotalFruits(parentBranch->getFruitsTotal() - 1);

    TREE_CLASS* parentTree = parentBranch->getTreePointer();
    if (!parentTree) return;
    parentTree->setTotalWeight(parentTree->getWeightsTotal()- weight);
    parentTree->setTotalFruits(parentTree->getFruitsTotal() - 1);

    GARDEN_CLASS* parentGarden = parentTree->getGardenPointer();
    if (!parentGarden) return;
    parentGarden->setTotalWeight(parentGarden->getWeightsTotal()-weight);
    parentGarden->setTotalFruits(parentGarden->getFruitsTotal() - 1);

}
FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS &other) {
    present = other.present;
    next = 0;
    prev = 0;
    weight = other.weight;
    positionInBranch = other.positionInBranch;
    parentBranch = 0;
}

//----------------operations-------------------
void FRUIT_CLASS::growthFruit(){
    if (!present) return;
    weight++;

    if (parentBranch == 0) return;
    parentBranch->setTotalWeight(parentBranch->getWeightsTotal()+1);

    TREE_CLASS* parentTree = parentBranch->getTreePointer();
    if (!parentTree) return;
    parentTree->setTotalWeight(parentTree->getWeightsTotal()+1);

    GARDEN_CLASS* parentGarden = parentTree->getGardenPointer();
    if (!parentGarden) return;
    parentGarden->setTotalWeight(parentGarden->getWeightsTotal()+1);


}
void FRUIT_CLASS::fadeFruit(){
    if (weight <= 0 || !present) return;
    weight--;

    if (!parentBranch) return;
    parentBranch->setTotalWeight(parentBranch->getWeightsTotal()-1);

    TREE_CLASS* parentTree = parentBranch->getTreePointer();
    if (!parentTree) return;
    parentTree->setTotalWeight(parentTree->getWeightsTotal()-1);

    GARDEN_CLASS* parentGarden = parentTree->getGardenPointer();
    if (!parentGarden) return;
    parentGarden->setTotalWeight(parentGarden->getWeightsTotal()-1);
}
void FRUIT_CLASS::pluckFruit(){

    unsigned formerWeight = weight;
    weight = 0;

    if (!parentBranch) return;
    parentBranch->setTotalWeight(parentBranch->getWeightsTotal()- formerWeight);

    TREE_CLASS* parentTree = parentBranch->getTreePointer();
    if (!parentTree) return;
    parentTree->setTotalWeight(parentTree->getWeightsTotal()-formerWeight);

    GARDEN_CLASS* parentGarden = parentTree->getGardenPointer();
    if (!parentGarden) return;
    parentGarden->setTotalWeight(parentGarden->getWeightsTotal()-formerWeight);
}

//---------------getters-------------------

unsigned int FRUIT_CLASS::getLength() const{
    return positionInBranch;
}
unsigned int FRUIT_CLASS::getWeight() const{
    return weight;
}
BRANCH_CLASS* FRUIT_CLASS::getBranchPointer(){
    return parentBranch;
}
FRUIT_CLASS* FRUIT_CLASS::getNext() const{
    return next;
}
FRUIT_CLASS* FRUIT_CLASS::getPrev() const{
    return prev;
}



//----------------setters----------------------

void FRUIT_CLASS::setNext(FRUIT_CLASS* nextFruit) {
    next = nextFruit;
}
void FRUIT_CLASS::setPrev(FRUIT_CLASS* prevFruit) {
    prev = prevFruit;
}
void FRUIT_CLASS::setWeight(unsigned fruitWeight) {
    if (!present) return;
    weight = fruitWeight;
}
void FRUIT_CLASS::setParentBranch(BRANCH_CLASS* branch) {
    parentBranch = branch;
    parentBranch->setLength(parentBranch->getLength()+1);

    if (present){
        parentBranch->setTotalFruits(parentBranch->getFruitsTotal()+1);
        parentBranch->setTotalWeight(parentBranch->getWeightsTotal()+weight);

        TREE_CLASS* parentTree = parentBranch->getTreePointer();
        if (!parentTree) return;
        parentTree->setTotalFruits(parentTree->getFruitsTotal()+1);
        parentTree->setTotalWeight(parentTree->getWeightsTotal()+weight);

        GARDEN_CLASS* parentGarden = parentTree->getGardenPointer();
        if (!parentGarden) return;
        parentGarden->setTotalFruits(parentTree->getFruitsTotal()+1);
        parentGarden->setTotalWeight(parentGarden->getWeightsTotal()+ weight);
    }
}
void FRUIT_CLASS::setPresent(bool a){
    present = a;
}
bool FRUIT_CLASS::getPresent() const{
    return present;
}
void FRUIT_CLASS::setLength(unsigned a){
    positionInBranch = a;
}

