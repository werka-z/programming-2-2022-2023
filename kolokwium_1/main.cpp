#include "Game.h"

/*
 * zmiany:
 * 1. Table: poprawienie malloc(a * sizeof(char)) na malloc(a * sizeof(char*)) dla rzędów (konstruktory i, operator przypisania)
 * 2. Table: operator przypisania: miał zwalnianie pamięci przed przypisaniem i używał new/delete zamiast malloc/free
 * 3. Table: 2 warunki nie były uwzględniane w liczeniu sąsiadów
 * 4. Table: usuniecie operatora [] - używanie table.table[][]
 *
 * 5: DataInterface/Game: zapis do plików zamiast wypisywania na stdout, skanowanie i zapisywanie za każdym razem (wcześniej tylko raz skanowane i wyświetlane na stdout)
 * 6. DataInterface: odczytanie rozmiaru tablicy, poprawne pomijanie '\n'
*/

int main() {

    Game game;
    game.play();

    return 0;
}


