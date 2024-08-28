//Weronika Zygis
void PrintHlpr(int set, int i, char* result, int index) {
   if (i < 0) {
       *(result + index) = '\0';
       return;
   }
   if (set & (1 << i)) {
       *(result + index  ) = (char)('0' + ((i>>4)%2));
       *(result + index+1) = (char)('0' + (i>>3) % 2);
       *(result + index+2) = (char)('0' + ((i>>2) %2));
       *(result + index+3) = (char)('0' + ((i>>1) %2));
       *(result + index+4) = (char)('0' + (i % 2));
       if (i != 0) *(result + index + 5) = ' ';
       index += (i == 0) ? 5 : 6;
   }
   PrintHlpr(set, i - 1, result, index);
}

int Strtoint(char* input, int& x) {// ciag znakowy -> zbior
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
       return Strtoint(input + 5, x);
   }
   else return Strtoint(input +1, x);
}


