//Weronika Zygis

class BRANCH_CLASS;
class FRUIT_CLASS{

private:
    bool present;

    FRUIT_CLASS* next;
    FRUIT_CLASS* prev;

    unsigned int weight;
    unsigned int positionInBranch;

    BRANCH_CLASS* parentBranch;

public:
    FRUIT_CLASS();
    ~FRUIT_CLASS();
    FRUIT_CLASS(const FRUIT_CLASS &other);
    unsigned int getLength() const;
    unsigned int getWeight() const;
    void growthFruit();
    void fadeFruit();
    void pluckFruit();
    BRANCH_CLASS* getBranchPointer();
    FRUIT_CLASS* getNext() const;
    FRUIT_CLASS* getPrev() const;

    void setNext(FRUIT_CLASS* nextFruit);
    void setPrev(FRUIT_CLASS* prevFruit);
    void setWeight(unsigned int fruitWeight);
    void setParentBranch(BRANCH_CLASS* branch);
    void setPresent(bool);
    bool getPresent()const;
    void setLength(unsigned );
    void display();
};
