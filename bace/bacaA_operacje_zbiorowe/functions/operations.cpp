//Weronika Zygis
void Union (int A, int B, int* result){
    *result = A | B;
}

void Intersection (int A, int B, int* result){
    *result = A & B;
}

void Symmetric (int A, int B, int* result){
    *result = A ^ B;
}

void Difference (int A, int B, int* result){
    *result = A & (~B);
}

void Complement (int set, int* result){
    *result = ~set;
}