#include "Pytanie.h"

class Oceniacz {
public:
    virtual int ocen(Pytanie)=0;
};

class Surowy : public Oceniacz{
    int ocen(Pytanie) override;
};

class Lagodny : public Oceniacz{
    int ocen(Pytanie) override;
};

class Obiektywny : public Oceniacz{
    int ocen(Pytanie) override;
};