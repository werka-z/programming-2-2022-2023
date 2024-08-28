//Weronika Zygis
int Strtoint(char*, int);
bool Member(char* subset, int set){
    return ((Strtoint(subset, 0) & set) ==  Strtoint(subset, 0));
}