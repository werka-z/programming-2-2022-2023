#include <iostream>
#include "Egzaminator.h"
#include "Pytanie.h"
#include "Test_Student.h"

int main() {
    Student student1("Anna", "Kowalska");
    Student student2("Jan", "Piotrowski");

    Pytanie pytanie1(2), pytanie2(3), pytanie3(1);
    pytanie1.setOdp(0, TP);
    pytanie1.setOdp(1, FN);
    pytanie2.setOdp(0, FP);
    pytanie2.setOdp(1, FN);
    pytanie2.setOdp(2, TN);
    pytanie3.setOdp(0, TP);

    Test test1(&student1);
    test1.dodajPytanie(pytanie1);
    test1.dodajPytanie(pytanie2);
    Test test2(&student2);
    test2.dodajPytanie(pytanie2);
    test2.dodajPytanie(pytanie3);

    // Tworzenie egzaminatorów z różnymi drukarzami i oceniaczami
    DrukarzCSV drukarzCSV;
    DrukarzStdout drukarzStdout;
    DrukarzJSON drukarzJSON;
    Lagodny oceniaczLagodny;
    Surowy oceniaczSurowy;
    Obiektywny oceniaczObiektywny;

    Egzaminator egzaminator1(&drukarzCSV, &oceniaczLagodny);
    Egzaminator egzaminator2(&drukarzStdout, &oceniaczSurowy);
    Egzaminator egzaminator3(&drukarzJSON, &oceniaczObiektywny);


    cout << "a ";
    egzaminator1.dodajTest(test1);
    egzaminator1.dodajTest(test2);
    cout << "b ";
    egzaminator1.ocenWszystko();
    egzaminator1.drukujWszystko();
    cout << "c ";

    egzaminator2.dodajTest(test1);
    egzaminator2.dodajTest(test2);
    egzaminator2.ocenWszystko();
    egzaminator2.drukujWszystko();

    egzaminator3.dodajTest(test1);
    egzaminator3.dodajTest(test2);
    egzaminator3.ocenWszystko();
    egzaminator3.drukujWszystko();

    return 0;
}

