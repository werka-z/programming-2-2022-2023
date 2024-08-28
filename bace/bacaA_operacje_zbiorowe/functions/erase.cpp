//Weronika Zygis
int Strtoint(char*, int);
void Erase(char* input, int* result_set){
    *result_set ^= (Strtoint(input, 0)& *result_set);
}
