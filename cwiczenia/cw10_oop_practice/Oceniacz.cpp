#include "Oceniacz.h"

/*
 * tp: zaznaczył prawidłową
 * fp: zaznaczył nieprawidłową
 * tn: nie zaznaczył prawidłowej
 * fn: nie zaznaczył nieprawidłowej
 */


int Surowy::ocen(Pytanie p){
    //tp 1, fp -1, tn -1, fn 0
    int points = 0;
    for (int i=0; i<p.getlOdp(); i++){
        switch (p.getOdp(i)){
            case TP:
                points++;
                break;
            case FP:
                points--;
                break;
            case TN:
                points--;
                break;
            default:
                break;
        }
    }
    return points;
}

int Lagodny::ocen(Pytanie p){
    // tp 1, fp 0, tn 0, fn 1
    int points = 0;
    for (int i=0; i<p.getlOdp(); i++){
        switch (p.getOdp(i)){
            case TP:
                points++;
                break;
            case FN:
                points++;
                break;
            default:
                break;
        }
    }
    return points;
}

int Obiektywny::ocen(Pytanie p){
    // tp 1, fp -1, tn 0, fn 0

    int points = 0;
    for (int i=0; i<p.getlOdp(); i++){
        switch (p.getOdp(i)){
            case TP:
                points++;
                break;
            case FP:
                points--;
                break;
            default:
                break;
        }
    }
    return points;
}

