#ifndef ZADA_BITWISE_OPERATIONS_H
#define ZADA_BITWISE_OPERATIONS_H

bool Emptiness (int set);
int Cardinality(int set);
bool Nonempty(int set);
bool LessThen(int A, int B); //probably
bool LessEqual(int A, int B); //probs
bool GreatEqual(int A, int B);//probs
bool GreatThen (int A, int B); //probably
bool Disjoint(int A, int B);
bool Conjunctive(int A, int B);
bool Inclusion(int A, int B);
bool Equality(int A, int B);
void Union (int A, int B, int* result);
void Intersection (int A, int B, int* result);
void Symmetric (int A, int B, int* result);
void Difference (int A, int B, int* result);
void Complement (int set, int* result);
void Emplace (char* input, int* result_set);
void Insert(char* input, int* target_set);
void Erase(char* input, int* result_set);
void Print(int set, char* result);
bool Member(char* subset, int set);

#endif //ZADA_BITWISE_OPERATIONS_H
