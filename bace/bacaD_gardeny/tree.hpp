//Weronika Zygis

class BRANCH_CLASS;
class GARDEN_CLASS;


class TREE_CLASS{

private:
    bool present;
    unsigned int id;
    unsigned int height;
    unsigned int numBranches;
    unsigned int totalNumFruits;
    unsigned int totalWeight;

    BRANCH_CLASS* firstBranch;
    BRANCH_CLASS* lastBranch;
    TREE_CLASS* next;
    TREE_CLASS* prev;

    GARDEN_CLASS* parentGarden;


public:
    TREE_CLASS();
    ~TREE_CLASS();
    TREE_CLASS(const TREE_CLASS& other);
    unsigned int getBranchesTotal() const;
    unsigned int getFruitsTotal() const;
    unsigned int getWeightsTotal() const;
    unsigned int getNumber() const;
    unsigned int getHeight() const;
    bool getPresent() const;
    void growthTree();
    void fadeTree();
    void harvestTree(unsigned int w);
    void cutTree(unsigned int h);
    void cloneBranch (BRANCH_CLASS* branch);
    GARDEN_CLASS* getGardenPointer() const;
    BRANCH_CLASS* getBranchPointer(unsigned);

    TREE_CLASS* getNext() const;
    TREE_CLASS* getPrev() const;

    void setNext(TREE_CLASS* nextTree);
    void setPrev (TREE_CLASS* pTree);
    void setHeight(unsigned );
    void setTotalBranches(unsigned );
    void setTotalFruits(unsigned );
    void setTotalWeight(unsigned );
    void setParentGarden(GARDEN_CLASS* const);
    void setPresent(bool);
    void setFirstBranch(BRANCH_CLASS*);
    void setLastBranch(BRANCH_CLASS*);
    void setNumber(unsigned);

    void setParent (GARDEN_CLASS* const);
    void display();
};


