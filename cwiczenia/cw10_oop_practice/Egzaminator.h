#include "Oceniacz.h"
#include "Drukarz.h"


class Egzaminator : public Oceniacz, public Drukarz{
    Oceniacz *oceniacz;
    Drukarz *drukarz;
    Test* testy;
    int lTestow;

public:
    Egzaminator(Drukarz*, Oceniacz*, int lTestow=0);
    ~Egzaminator();
    int ocen(Pytanie) override;
    void drukuj(Test) override;
    void dodajTest(const Test&);
    void ocenWszystko();
    void drukujWszystko();
};