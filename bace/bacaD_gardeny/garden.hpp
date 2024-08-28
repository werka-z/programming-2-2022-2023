//Weronika Zygis
class BRANCH_CLASS;
class TREE_CLASS;

class GARDEN_CLASS{
private:

    unsigned int sizeOfGarden;
    unsigned int numTrees;
    unsigned int numBranches;
    unsigned int numFruits;
    unsigned int totalWeight;
    unsigned int lowestFreeID;

    TREE_CLASS* firstTree;
    TREE_CLASS* lastTree;

public:
    GARDEN_CLASS();
    ~GARDEN_CLASS();
    GARDEN_CLASS(const GARDEN_CLASS& other);
    unsigned int getTreesTotal() const;
    unsigned int getBranchesTotal() const;
    unsigned int getFruitsTotal() const;
    unsigned int getWeightsTotal() const;
    void plantTree ();
    void extractTree(unsigned int);
    void growthGarden();
    void fadeGarden();
    void harvestGarden(unsigned int weight);
    TREE_CLASS* getTreePointer(unsigned int id);
    void cloneTree (unsigned int a);

    void setTotalTrees(unsigned);
    void setTotalBranches(unsigned);
    void setTotalFruits(unsigned );
    void setTotalWeight(unsigned );
    void setFirstTree(TREE_CLASS*);
    void setLastTree(TREE_CLASS*);

    void setLowestFreeID (unsigned);
    unsigned getLowestFreeID();
    void setGardenSize(unsigned );
    unsigned getGardenSize() const;

    void display();


};
