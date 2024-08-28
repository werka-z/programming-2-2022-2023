//Weronika Zygis
class FRUIT_CLASS;
class TREE_CLASS;
class BRANCH_CLASS{
private:
    bool present;

    unsigned int length;
    unsigned int numFruits;
    unsigned int totalWeight;
    unsigned int heightOnTree;

    FRUIT_CLASS* firstFruit;
    FRUIT_CLASS* lastFruit;

    BRANCH_CLASS* prev;
    BRANCH_CLASS* next;

    TREE_CLASS* parentTree;


public:

    BRANCH_CLASS();
    ~BRANCH_CLASS();
    BRANCH_CLASS (const BRANCH_CLASS&);
    unsigned int getFruitsTotal() const;
    unsigned int getWeightsTotal() const;
    unsigned int getHeight() const;
    unsigned int getLength() const;
    void growthBranch();
    void fadeBranch();
    void harvestBranch(unsigned int weight);
    void cutBranch (unsigned int length);
    FRUIT_CLASS* getFruitPointer(unsigned int a);
    TREE_CLASS* getTreePointer();


    void setLength(unsigned int l);
    void setTotalFruits(unsigned int nf);
    void setTotalWeight(unsigned int tW);
    void setHeightOnTree(unsigned int h);
    void setFirstFruit(FRUIT_CLASS* fF);
    void setLastFruit(FRUIT_CLASS* lF);
    void setPrev(BRANCH_CLASS* p);
    void setNext(BRANCH_CLASS* n);
    void setParentTree(TREE_CLASS* parTree);
    void setPresent (bool);

    BRANCH_CLASS* getNext() const;
    BRANCH_CLASS* getPrev() const;

    bool getPresent() const;
    void display();
    //void setParent(TREE_CLASS* p);
};
