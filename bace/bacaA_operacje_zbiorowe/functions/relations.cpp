//Weronika Zygis
int Cardinality(int);

bool LessThen(int A, int B){
    int a = Cardinality(A);
    int b = Cardinality(B);
    if (a==b) return (B>A);
    return (a<b);
}

bool LessEqual(int A, int B){
    if (A == B) return true;
    return LessThen(A, B);
}

bool GreatEqual(int A, int B){
    return !LessThen(A, B);
}

bool GreatThen (int A, int B){
    return !LessEqual(A, B);
}


