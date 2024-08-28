#include "Pytanie.h"

class Drukarz{
public:
    virtual void drukuj(Test)=0;
};

class DrukarzCSV : public Drukarz{
    int counter = 0;
    void drukuj(Test) override;
};

class DrukarzJSON : public Drukarz{
    int counter = 0;
    void drukuj(Test) override;
};

class DrukarzStdout : public Drukarz{
    void drukuj(Test) override;
};
