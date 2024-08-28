//Weronika Zygis

#include <iostream>
#include <string>

#define Player PLAYER_CLASS
#define Caesar CAESAR_CLASS
#define Human  HUMAN_CLASS
#define Beast BEAST_CLASS
#define Berserker BERSERKER_CLASS
#define Squad SQUAD_CLASS
#define Arena ARENA_CLASS

#define judge judgeDeathOfLife
#define makeWinner applyWinnerReward
#define getRHP getRemainingHealth

typedef unsigned int uint;
using namespace std;

//---------abstract base class--------
class Player {
protected:
    uint maxHP;
    uint HP;
    uint damage;
    uint agility;
    Player* next;

    virtual void die() { HP = 0; }

public:

    Player(){}
    //virtual ~Player() {}

    Player(uint maxHealth, uint currHealth, uint damage, uint agility) : maxHP(maxHealth), HP(currHealth), damage(damage), agility(agility) , next(0){}

    virtual uint getDamage() { return damage; }
    virtual uint getAgility() { return agility; }
    virtual uint getRHP() {return (100 * HP)/maxHP; }

    virtual void takeDamage(uint amount) {
        if (amount >= HP) {
            HP = 0;
        }
        else if (amount > 0)
            HP -= amount;

        if (getRemainingHealth() == 0) die();
    }

    virtual void makeWinner() {
        agility+=2;
        damage+=2;
    }

    virtual void cure() {
        HP = maxHP;
    }

    virtual string getName() {
        return "";
    }

    Player* getNext(){
        return next;
    };
    void setNext(Player* P){
        next = P;
    }

    virtual void printParams() {
        cout << maxHP << ":" << HP << ":" << getRHP() << "%:" << getDamage() << ":" << getAgility();
    }

    friend class Caesar;
    friend class Arena;
    friend class Squad;
};

//void Player::printParams(){
//    cout << maxHP << ":" << HP << ":" << getRHP() << "%:" << getDamage() << ":" << getAgility();
//}



//----------caesar-----------
class Caesar {
public:
    uint attackCount;
    uint sentenceCount;

    //Caesar() : attackCount(0), sentenceCount(0) {}

    void judge(Player *p) {
        sentenceCount++;
        if (sentenceCount % 3 == 0) {
            sentenceCount = 0;
            if (attackCount % 2 == 0) p->die();
        }
    }
};

//-----------player classes----------
class Human : public virtual Player {
    protected:
        string id;
        uint defence;

    public:

        Human(string const &id_) : Player(200, 200, 30, 10), defence(10), id(id_) {}

        virtual string getName() {
            return id;
        }

        virtual void takeDamage(uint amount) {
            if (amount > (defence + getAgility())) {
                uint dam = amount - (defence + getAgility());
                Player::takeDamage(dam);
            }
        }

        virtual void printParams() {
            if (getRHP() > 0) {
                cout << id << ":";
                Player::printParams();
                cout << ":" << defence << endl;
            } else cout << id << ":R.I.P." << endl;
        }

    };

class Beast : public virtual Player {
    protected:
        string id;
    public:
        Beast(string const &id_) : Player(150, 150, 40, 20), id(id_) {}

        virtual uint getDamage() {
            if (getRHP() < 25) return (2 * (Player::damage));
            else return Player::damage;
        }

        virtual string getName() {
            return id;
        }

        virtual void takeDamage(uint amount) {
            if (amount > (getAgility() / 2)) {
                uint dam = amount - getAgility() / 2;
                Player::takeDamage(dam);
            }
        }

        virtual void printParams() {
            cout << id << ":";
            if (getRHP() > 0) {
                Player::printParams();
                cout << endl;
            } else cout << "R.I.P." << endl;
        }

    };

class Berserker : public virtual Beast, public virtual Human {
        string idHuman;
        string idBeast;

    public:
        Berserker(string const &id1_, string const &id2_) : Player(200, 200, 35, 5), Human(id1_), Beast(id2_) { defence = 15; }

        string getName() {
            uint rhp = getRemainingHealth();
            if (rhp < 25 && rhp > 0) return Beast::getName();
            else return Human::getName();
        }

        uint getDamage() {
            uint rhp = getRemainingHealth();
            if (rhp < 25 && rhp > 0) return Beast::getDamage();
            else return Human::getDamage();
        }

        uint getAgility() {
            uint rhp = getRemainingHealth();
            if (rhp < 25 && rhp > 0) return Beast::getAgility();
            else return Human::getAgility();
        }

        void takeDamage(uint amount) {
            uint rhp = getRemainingHealth();
            if (rhp < 25 && rhp > 0) Beast::takeDamage(amount);
            else Human::takeDamage(amount);
        }

        void printParams() {
            uint rhp = getRemainingHealth();
            if (rhp < 25 && rhp > 0) Beast::printParams();
            else Human::printParams();
        }

    };

class Squad : public virtual Player {
        string id;
        uint size;
        Player *firstPlayer;

    public:
        Squad(string const &id_) : Player(200, 200, 30, 10), id(id_),
        size(0), firstPlayer(0) {}

        void addPlayer(Player *P) {
            if (P->getRHP() == 0) return;
            if (!firstPlayer) {
                firstPlayer = P;
                size ++;
                return;
            }
            Player *ptr = firstPlayer;
            while (ptr->getNext()) {
                if (ptr->getNext() == P) return;
                ptr = ptr->getNext();
            }
            size ++;
            ptr->setNext(P);
        }

        string getName() {
            return id;
        }

        void makeWinner() {
            if (!firstPlayer) return;
            Player *ptr = firstPlayer;
            while (ptr) {
                ptr->makeWinner();
                ptr = ptr->getNext();
            }
        }

        void cure() {
            if (!firstPlayer) return;
            Player *ptr = firstPlayer;
            while (ptr) {
                ptr->cure();
                ptr = ptr->getNext();
            }
        }

        void die() {
            if (!firstPlayer) return;
            Player *ptr = firstPlayer;
            while (ptr) {
                ptr->die();
                ptr = ptr->getNext();
            }
            size = 0;
            firstPlayer = 0;
        }

        uint getAgility() { //najmniejsza zwinnosc czlonkow zespolu
            if (!firstPlayer) return 0;
            Player *ptr = firstPlayer;
            uint min = firstPlayer->getAgility();
            while (ptr) {
                uint ag = ptr->getAgility();
                if (ag < min) min = ag;
                ptr = ptr->getNext();
            }
            return min;
        };

        uint getDamage() {//sume damage wszystkich czlonkow zespolu
            if (!firstPlayer) return 0;
            Player *ptr = firstPlayer;
            uint sum = 0;
            while (ptr) {
                sum += ptr->getDamage();
                ptr = ptr->getNext();
            }
            return sum;
        };

        uint getRHP() {//najwieksze rhp czlonka
            if (!firstPlayer) return 0;
            Player *ptr = firstPlayer;
            uint max = 0;
            while (ptr) {
                uint M = ptr->getRemainingHealth();
                if (M > max) max = M;
                ptr = ptr->getNext();
            }
            return max;
        };

        void takeDamage(uint amount) {
            if (!size) return;
            amount /= size;
            Player *ptr = firstPlayer;
            Player *prev = 0;

            while (ptr) {
                ptr->takeDamage(amount);
                Player *next = ptr->getNext();
                if (ptr->getRemainingHealth() == 0) {
                    rmPlayer(prev, ptr);
                    ptr = 0;
                }
                if (ptr) prev = ptr;
                ptr = next;
            }
            if (getRemainingHealth() == 0) die();
        }

        void rmPlayer(Player *prev, Player *P) {
            if (size==0) return;
            if (P == firstPlayer) {
                firstPlayer = P->getNext();
                //firstPlayer = 0;
                size--;
                return;
            }
            if (prev) {
                prev->setNext(P->getNext());
                size--;
            }
        }

        void swap(Player *prev, Player *A, Player *B) {
            if (prev) prev->setNext(B);
            A->setNext(B->getNext());
            B->setNext(A);
            if (A == firstPlayer) firstPlayer = B;
        }

        static bool secondComesFirst(Player *A, Player *B) {
            if (B->getName() < A->getName()) return true;
            if (B->getName() > A->getName()) return false;

            if (B->maxHP < A->maxHP) return true;
            if (B->maxHP > A->maxHP) return false;

            if (B->HP < A->HP) return true;
            if (B->HP > A->HP) return false;

            if (B->getDamage() < A->getDamage()) return true;
            if (B->getDamage() > A->getDamage()) return false;

            if (B->getAgility() < A->getAgility()) return true;
            return false;
        }

        void bubbleSort() {//sort for id maxhp and hp
            if (!firstPlayer || !firstPlayer->getNext()) return;

            Player *PREV;
            Player *A;
            Player *B;

            bool swapped;
            for (int i = 0; i < size - 1; i++) {
                PREV = 0;
                A = firstPlayer;
                B = A->getNext();
                swapped = false;

                for (int j = i; j < size - 1; j++) {
                    if (secondComesFirst(A, B)) {
                        swap(PREV, A, B);
                        Player *temp = A;
                        A = B;
                        B = temp;
                        swapped = true;
                    }
                    PREV = A;
                    A = B;
                    if (B) B = B->getNext();
                }
                if (!swapped) break;
            }
        }

        void printParams() {
            if (size == 0) {
                cout << id << ":nemo" << endl;
                return;
            }

            bubbleSort();

            cout << id << ":" << size << ":" << getRemainingHealth() << "%:" << getDamage() << ":" << getAgility() << endl;

            Player *ptr = firstPlayer;
            while (ptr) {
                ptr->printParams();
                ptr = ptr->getNext();
            }
        }
    };


//-----------arena
class Arena {
private:
        Caesar caesar;

public:
        Arena(Caesar* c_) {
            caesar = *c_;
        }

        void fight(Player *Selena, Player *Hailey) {
            if (Selena->getRHP() <= 0 || Hailey->getRHP() <= 0) return;
            if (Selena == Hailey) return;

            Player *p1 = Selena;
            Player *p2 = Hailey;

            if (Hailey->getAgility() > Selena->getAgility()) {
                p1 = Hailey;
                p2 = Selena;
            }

            p1->printParams();
            p2->printParams();

            caesar.attackCount = 0;
            for (int i = 0; i < 20; i++) {

                if (p1->getRemainingHealth() < 10) break;

                p2->takeDamage(p1->getDamage());
                if (p2->getRHP() == 0) p2->die();
                p2->printParams();
                caesar.attackCount++;

                if (p2->getRemainingHealth() < 10) break;

                p1->takeDamage(p2->getDamage());
                if (p1->getRHP() == 0) p1->die();
                p1->printParams();
                caesar.attackCount++;
            }

            if (p1->getRHP() > 0) {
                caesar.judge(p1);
                p1->printParams();
                if (p1->getRHP() > 0) {
                    p1->makeWinner();
                    p1->cure();
                }
            }
            if (p2->getRHP() > 0) {
                caesar.judge(p2);
                p2->printParams();
                if (p2->getRHP() > 0) {
                    p2->makeWinner();
                    p2->cure();
                }
            }

            p1->printParams();
            p2->printParams();
        }

    };
