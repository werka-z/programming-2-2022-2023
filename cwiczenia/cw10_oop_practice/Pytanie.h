#include <string>
using namespace std;
class Test;

enum Odp{
    TP, FP, TN, FN
};

class Pytanie{
    int lOdp;
    Odp* odp;

public:
    Pytanie();
    explicit Pytanie(int);
    ~Pytanie();
    void setOdp(int, Odp);
    int getTP();
    int getFP();
    int getTN();
    int getFN();
    int getlOdp() const;
    Odp getOdp(int) const;
    string getOdpStr(int i) const;
    string toJSON() const;
    string toCSV() const;
    void display();

};