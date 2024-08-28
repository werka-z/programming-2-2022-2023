//Weronika Zygis
bool Disjoint(int A, int B){
    //true: and na bitach == 0
    return (A & B) == 0;
}

bool Conjunctive(int A, int B){
    return (A & B) != 0;
}
