#pragma once
#include "source.cpp"


void test(int num) {
    switch (num) {
        case 1: {
            CAESAR_CLASS caesar;
            ARENA_CLASS arena(&caesar);

            HUMAN_CLASS h1("h1");
            HUMAN_CLASS h2("h2");

            SQUAD_CLASS squad1("FIRST");
            SQUAD_CLASS squad2("SECON");

            squad1.addPlayer(&h1);
            squad1.addPlayer(&h2);
            squad2.addPlayer(&h1);
            squad2.addPlayer(&h2);

            arena.fight(&squad1, &squad2);
            arena.fight(&squad2, &squad1);
            break;
        }
        case 2: {
            CAESAR_CLASS caesar;
            ARENA_CLASS arena(&caesar);

            BEAST_CLASS b1("b1");
            HUMAN_CLASS h1("h1");
            HUMAN_CLASS h2("h2");
            HUMAN_CLASS h3("h3");

            SQUAD_CLASS squad2("SECON");
            SQUAD_CLASS squad1("FIRST");

            squad2.addPlayer(&h1);
            squad2.addPlayer(&h2);
            squad2.addPlayer(&b1);
            squad2.addPlayer(&h3);

            squad1.addPlayer(&h1);
            squad1.addPlayer(&h2);
            squad1.addPlayer(&b1);
            squad1.addPlayer(&h3);


            arena.fight(&squad1, &squad2);
            arena.fight(&squad2, &squad1);

            BEAST_CLASS b2("b2");
            squad1.addPlayer(&b2);

            arena.fight(&squad1, &squad2);
            arena.fight(&squad2, &squad1);

            break;
        }
        case 3: {
            CAESAR_CLASS caesar;
            ARENA_CLASS arena(&caesar);

            SQUAD_CLASS h1("h1");
            SQUAD_CLASS b1("b1");

            caesar.judgeDeathOfLife(&h1);
            caesar.judgeDeathOfLife(&h1);

            arena.fight(&h1, &b1);
            break;
        }
        case 4: {
            CAESAR_CLASS caesar;
            ARENA_CLASS arena(&caesar);

            BERSERKER_CLASS r1("hr2", "br1");
            BERSERKER_CLASS r2("hr2", "br1");

            BEAST_CLASS b1("b1");
            HUMAN_CLASS h1("h1");
            HUMAN_CLASS h2("h2");
            HUMAN_CLASS h3("h3");

            SQUAD_CLASS squad1("FIRST");
            SQUAD_CLASS squad2("SECON");

            squad1.addPlayer(&h1);
            squad1.addPlayer(&h2);
            squad1.addPlayer(&h3);
            squad1.addPlayer(&b1);
            squad1.addPlayer(&r1);
            squad2.addPlayer(&h1);
            squad2.addPlayer(&h2);
            squad2.addPlayer(&h3);
            squad2.addPlayer(&b1);
            squad2.addPlayer(&r2);

            arena.fight(&squad1, &squad2);
            arena.fight(&squad2, &squad1);
            break;
        }
        case 5: {
            break;
        }
        case 6: {
            break;
        }
        case 7: {
            break;
        }
        case 8: {
            CAESAR_CLASS caesar;
            ARENA_CLASS arena(&caesar);

            HUMAN_CLASS human1("human1");
            BEAST_CLASS beast1("beast1");
            BERSERKER_CLASS berserker1("berserker-human1", "berserker-beast1");

            HUMAN_CLASS dead("dead-human");
            dead.takeDamage(500);

            SQUAD_CLASS squad("squad");
            squad.addPlayer(&human1);
            squad.addPlayer(&beast1);
            squad.addPlayer(&berserker1);
            squad.addPlayer(&dead);
            squad.addPlayer(&human1);
            squad.addPlayer(&beast1);
            squad.addPlayer(&berserker1);


            HUMAN_CLASS human2("human2");

            arena.fight(&squad, &human2);

            SQUAD_CLASS sq("squaT");
            sq.addPlayer(&human2);
            sq.addPlayer(&berserker1);

            arena.fight(&sq, &squad);
            sq.applyWinnerReward();
            sq.applyWinnerReward();
            sq.applyWinnerReward();
            squad.applyWinnerReward();
            squad.applyWinnerReward();
            arena.fight(&sq, &squad);
            break;
        }
        case 9: {
            CAESAR_CLASS caesar;
            ARENA_CLASS arena(&caesar);

            HUMAN_CLASS human1("human1");
            BEAST_CLASS beast1("beast1");
            BERSERKER_CLASS berserker1("berserker-human1", "berserker-beast1");

            HUMAN_CLASS dead("dead-human");
            dead.takeDamage(500);

            SQUAD_CLASS squad("squad");
            squad.addPlayer(&human1);
            squad.addPlayer(&beast1);
            squad.addPlayer(&berserker1);
            squad.addPlayer(&dead);
            squad.addPlayer(&human1);
            squad.addPlayer(&beast1);
            squad.addPlayer(&berserker1);

            HUMAN_CLASS human2("human2");
            HUMAN_CLASS human3("human3");
            HUMAN_CLASS human4("human4");
            HUMAN_CLASS human5("human5");

            SQUAD_CLASS humansquad("humansquad");
            humansquad.addPlayer(&human2);
            humansquad.addPlayer(&human3);
            humansquad.addPlayer(&human4);
            humansquad.addPlayer(&human5);

            arena.fight(&humansquad, &squad);
            break;
        }
        case 10: {
            CAESAR_CLASS caesar;
            ARENA_CLASS arena(&caesar);

            BERSERKER_CLASS h("Herkules", "Herkulio");

            BEAST_CLASS b1("Lion");
            HUMAN_CLASS b2("Elephant");
            BEAST_CLASS b3("Tiger");
            BERSERKER_CLASS b4("Giraffe", "G");
            BERSERKER_CLASS b5("Dog", "D");

            SQUAD_CLASS animals("Animals");

            animals.addPlayer(&b1);
            animals.addPlayer(&b2);
            animals.addPlayer(&b3);
            animals.addPlayer(&b4);
            animals.addPlayer(&b5);

            HUMAN_CLASS human1("human1");
            BEAST_CLASS beast1("beast1");
            BERSERKER_CLASS berserker1("berserker-human1", "berserker-beast1");

            HUMAN_CLASS dead("dead-human");
            dead.takeDamage(500);

            SQUAD_CLASS squad("squad");
            squad.addPlayer(&human1);
            squad.addPlayer(&beast1);
            squad.addPlayer(&berserker1);
            squad.addPlayer(&dead);
            squad.addPlayer(&human1);
            squad.addPlayer(&beast1);
            squad.addPlayer(&berserker1);

            arena.fight(&squad, &animals);
            arena.fight(&animals, &squad);
            squad.cure();
            arena.fight(&squad, &animals);
        }
        default:
            break;
    }
}
int main() {
//    for (int i = 2; i <= 4; i++) {
//        std::cout << i << std::endl;
//        test(i);
//    }

    CAESAR_CLASS caesar;
    ARENA_CLASS arena(&caesar);

    HUMAN_CLASS human1("human1");
    BEAST_CLASS beast1("beast1");
    BERSERKER_CLASS berserker1("berserker-human1", "berserker-beast1");

    HUMAN_CLASS dead("dead-human");
    dead.takeDamage(500);

    SQUAD_CLASS squad("squad");
    squad.addPlayer(&human1);
    squad.addPlayer(&beast1);
    squad.addPlayer(&berserker1);
    squad.addPlayer(&dead);

    HUMAN_CLASS human2("human2");
    HUMAN_CLASS human3("human3");
    HUMAN_CLASS human4("human4");
    HUMAN_CLASS human5("human5");

    SQUAD_CLASS humansquad("humansquad");
    humansquad.addPlayer(&human2);
    humansquad.addPlayer(&human3);
    humansquad.addPlayer(&human4);
    humansquad.addPlayer(&human5);

    arena.fight(&humansquad, &squad);

}