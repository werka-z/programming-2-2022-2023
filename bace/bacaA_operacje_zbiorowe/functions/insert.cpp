//Weronika Zygis
int Strtoint(char* input, int x);
void Insert(char* input, int* target_set){
    *target_set |= Strtoint(input, 0);
}
