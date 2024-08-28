//Weronika Zygis
int Cardinality(int set) {
    if (set == 0) return 0;
    if (set == 1) return 1;

    int result =0;
    if (set & 1) result++;
    if ((set >> 1) & 1) result++;
    if ((set >> 2) & 1) result++;
    if ((set >> 3) & 1) result++;
    if ((set >> 4) & 1) result++;
    if ((set >> 5) & 1) result++;
    if ((set >> 6) & 1) result++;
    if ((set >> 7) & 1) result++;
    if ((set >> 8) & 1) result++;
    if ((set >> 9) & 1) result++;
    if ((set >> 10) & 1) result++;
    if ((set >> 11) & 1) result++;
    if ((set >> 12) & 1) result++;
    if ((set >> 13) & 1) result++;
    if ((set >> 14) & 1) result++;
    if ((set >> 15) & 1) result++;
    if ((set >> 16) & 1) result++;
    if ((set >> 17) & 1) result++;
    if ((set >> 18) & 1) result++;
    if ((set >> 19) & 1) result++;
    if ((set >> 20) & 1) result++;
    if ((set >> 21) & 1) result++;
    if ((set >> 22) & 1) result++;
    if ((set >> 23) & 1) result++;
    if ((set >> 24) & 1) result++;
    if ((set >> 25) & 1) result++;
    if ((set >> 26) & 1) result++;
    if ((set >> 27) & 1) result++;
    if ((set >> 28) & 1) result++;
    if ((set >> 29) & 1) result++;
    if ((set >> 30) & 1) result++;
    if ((set >> 31) & 1) result++;

    return result;
}

int Strtoint(char* input, int x) {// ciag znakowy -> zbior
    if(*input =='\0') return x;

    if (*input == '0' || *input == '1') {
        if (*input == '0') {
            if      (*(input + 1) == '0' && *(input + 2) == '0' && *(input + 3) == '0' && *(input + 4) == '0')x = (x | 1);
            else if (*(input + 1) == '0' && *(input + 2) == '0' && *(input + 3) == '0' && *(input + 4) == '1')x = (x | (1 << 1));
            else if (*(input + 1) == '0' && *(input + 2) == '0' && *(input + 3) == '1' && *(input + 4) == '0')x = (x | (1 << 2));
            else if (*(input + 1) == '0' && *(input + 2) == '0' && *(input + 3) == '1' && *(input + 4) == '1')x = (x | (1 << 3));
            else if (*(input + 1) == '0' && *(input + 2) == '1' && *(input + 3) == '0' && *(input + 4) == '0')x = (x | (1 << 4));
            else if (*(input + 1) == '0' && *(input + 2) == '1' && *(input + 3) == '0' && *(input + 4) == '1')x = (x | (1 << 5));
            else if (*(input + 1) == '0' && *(input + 2) == '1' && *(input + 3) == '1' && *(input + 4) == '0')x = (x | (1 << 6));
            else if (*(input + 1) == '0' && *(input + 2) == '1' && *(input + 3) == '1' && *(input + 4) == '1')x = (x | (1 << 7));
            else if (*(input + 1) == '1' && *(input + 2) == '0' && *(input + 3) == '0' && *(input + 4) == '0')x = (x | (1 << 8));
            else if (*(input + 1) == '1' && *(input + 2) == '0' && *(input + 3) == '0' && *(input + 4) == '1')x = (x | (1 << 9));
            else if (*(input + 1) == '1' && *(input + 2) == '0' && *(input + 3) == '1' && *(input + 4) == '0')x = (x | (1 << 10));
            else if (*(input + 1) == '1' && *(input + 2) == '0' && *(input + 3) == '1' && *(input + 4) == '1')x = (x | (1 << 11));
            else if (*(input + 1) == '1' && *(input + 2) == '1' && *(input + 3) == '0' && *(input + 4) == '0')x = (x | (1 << 12));
            else if (*(input + 1) == '1' && *(input + 2) == '1' && *(input + 3) == '0' && *(input + 4) == '1')x = (x | (1 << 13));
            else if (*(input + 1) == '1' && *(input + 2) == '1' && *(input + 3) == '1' && *(input + 4) == '0')x = (x | (1 << 14));
            else if (*(input + 1) == '1' && *(input + 2) == '1' && *(input + 3) == '1' && *(input + 4) == '1')x = (x | (1 << 15));
        }
        else if (*input == '1') {
            if (*(input + 1) == '0' && *(input + 2) == '0' && *(input + 3) == '0' && *(input + 4) == '0')x = (x | (1<< 16));
            else if (*(input + 1) == '0' && *(input + 2) == '0' && *(input + 3) == '0' && *(input + 4) == '1')x = (x |(1<< 17));
            else if (*(input + 1) == '0' && *(input + 2) == '0' && *(input + 3) == '1' && *(input + 4) == '0')x = (x |(1<< 18));
            else if (*(input + 1) == '0' && *(input + 2) == '0' && *(input + 3) == '1' && *(input + 4) == '1')x = (x |(1<< 19));
            else if (*(input + 1) == '0' && *(input + 2) == '1' && *(input + 3) == '0' && *(input + 4) == '0')x = (x |(1<< 20));
            else if (*(input + 1) == '0' && *(input + 2) == '1' && *(input + 3) == '0' && *(input + 4) == '1')x = (x |(1<< 21));
            else if (*(input + 1) == '0' && *(input + 2) == '1' && *(input + 3) == '1' && *(input + 4) == '0')x = (x |(1<< 22));
            else if (*(input + 1) == '0' && *(input + 2) == '1' && *(input + 3) == '1' && *(input + 4) == '1')x = (x |(1<< 23));
            else if (*(input + 1) == '1' && *(input + 2) == '0' && *(input + 3) == '0' && *(input + 4) == '0')x = (x |(1<< 24));
            else if (*(input + 1) == '1' && *(input + 2) == '0' && *(input + 3) == '0' && *(input + 4) == '1')x = (x |(1<< 25));
            else if (*(input + 1) == '1' && *(input + 2) == '0' && *(input + 3) == '1' && *(input + 4) == '0')x = (x |(1<< 26));
            else if (*(input + 1) == '1' && *(input + 2) == '0' && *(input + 3) == '1' && *(input + 4) == '1')x = (x |(1<< 27));
            else if (*(input + 1) == '1' && *(input + 2) == '1' && *(input + 3) == '0' && *(input + 4) == '0')x = (x |(1<< 28));
            else if (*(input + 1) == '1' && *(input + 2) == '1' && *(input + 3) == '0' && *(input + 4) == '1')x = (x |(1<< 29));
            else if (*(input + 1) == '1' && *(input + 2) == '1' && *(input + 3) == '1' && *(input + 4) == '0')x = (x |(1<< 30));
            else if (*(input + 1) == '1' && *(input + 2) == '1' && *(input + 3) == '1' && *(input + 4) == '1')x = (x |(1<< 31));
        }
        input += 5;
    }
    else input ++;
    return Strtoint(input, x);
}
