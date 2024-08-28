//Weronika Zygis
void PrintHlpr(int, int, char*, int, int);

void Print(int set, char* result) {
    if (set == 0) {
        *(result) = 'e';
        *(result+1) = 'm';
        *(result+2) = 'p';
        *(result+3) = 't';
        *(result+4) = 'y';
        *(result+5) = '\0';
    } else {
        PrintHlpr(set, 31, result, 0, 0);
    }
}

void PrintHlpr(int set, int i, char* result, int index, int not_first) {
    if (i < 0) {
         *(result + index) = '\0';
        return;
    }
    if (set & (1 << i)) {
        if (not_first){
            *(result + index) = ' ';
            index ++;
        }
        *(result + index  ) = (char)('0' + ((i/16) % 2));
        *(result + index+1) = (char)('0' + ((i/8) % 2));
        *(result + index+2) = (char)('0' + ((i/4) % 2));
        *(result + index+3) = (char)('0' + ((i/2) % 2));
        *(result + index+4) = (char)('0' + (i % 2));
        index += 5;
        not_first = 1;

    }
    PrintHlpr(set, i - 1, result, index, not_first);
}
