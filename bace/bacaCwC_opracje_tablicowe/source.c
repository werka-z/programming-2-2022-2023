//Weronika Zygis
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//----------------insert helpers----------------
void insertBlock(int r, int c, int h, int w, int **elements,  int *rowzz, int **colzz,int ***matrix);
void removeBlock(int r, int h, int c, int w, int *rowz, int **colz, int ***matrix);

//---------------------------rows-------------------------
void addFirstRow(int width, const int *elements, int *rowz, int **colz, int ***matrix){
    if (width<=0)return;
    int **new_matrix = (int **)realloc(*matrix, (*rowz + 1) * sizeof(int *));
    //if (new_matrix == NULL) exit(898);

    *matrix = new_matrix;
    int i;
    for ( i = *rowz; i > 0; --i) { //vvshiftvv
        *(*matrix+i) = *(*matrix+i - 1);
    }

    int *new_row = malloc(width * sizeof(int));
    //if (new_row == NULL) exit(787);

    for ( i = 0; i < width; ++i) {
        *(new_row + i) = *(elements + i);
    }
    //printf("checkpoint 7\n");
    *(*matrix) = new_row;
    int *new_colz = (int *)realloc(*colz, (*rowz + 1) * sizeof(int ));
    //if (new_colz == NULL) exit (555);
    *colz = new_colz;

    for (i = *rowz; i > 0; --i) {
        *(*colz + i) = *(*colz+i - 1);
    }
    *(*colz) = width;
    (*rowz)++;
}
void addLastRow(int width, const int *elements, int *rowz,int **colz, int ***matrix){
    if (width<=0) return;
    int **new_matrix = (int **)realloc(*matrix, (*rowz + 1) * sizeof(int *));
    //if (new_matrix == NULL) exit(898);

    *matrix = new_matrix;

    int *new_row = (int *)malloc(width * sizeof(int));
    //if (new_row == NULL) exit(787);
    int i;
    for ( i = 0; i < width; ++i) {
        *(new_row + i) = *(elements + i);
    }

    *(*matrix+ (*rowz)) = new_row;

    //printf("checkpoint 1\n");
    int *new_colz = (int *)realloc(*colz, (*rowz + 1) * sizeof(int ));
    //if (new_colz == NULL) exit (555);
    *colz = new_colz;
    //printf("checkpoint 2\n");

    *(*colz +(*rowz)) = width;
    (*rowz)++;
}
void insertBeforeRow(int row, int width, const int *elements, int *rowz, int **colz, int ***matrix){
    if (row >= *rowz) return;
    if (width<=0) return;
    if (row == 0) {
        addFirstRow(width, elements, rowz, colz, matrix);
        return;
    }
    int **new_matrix = (int **)realloc(*matrix, (*rowz + 1) * sizeof(int *));
    //if (new_matrix == NULL) exit(898);

    *matrix = new_matrix;

int i;
    for ( i = *rowz; i > row; --i) {
        *((*matrix)+i) = *((*matrix)+i - 1);
    }

    int *new_row = (int *)malloc(width * sizeof(int));
    //if (new_row == NULL) exit(787);

    for ( i = 0; i < width; ++i) {
        *(new_row + i) = *(elements + i);
    }

    *(*matrix + row) = new_row;

    int *new_colz = (int *)realloc(*colz, (*rowz + 1) * sizeof(int ));
    //if (new_colz == NULL) exit (555);
    *colz = new_colz;

    for ( i = *rowz; i > row; --i) {
        *(*colz+i) = *(*colz+i - 1);
    }

    *(*colz+row) = width;
    (*rowz)++;
}
void insertAfterRow(int row, int width, const int *elements, int *rowz, int **colz, int ***matrix){
    if (row >= *rowz) return;
    if (width<=0) return;

    int **new_matrix = (int **)realloc(*matrix, (*rowz + 1) * sizeof(int *));
   // if (new_matrix == NULL) exit(898);

    *matrix = new_matrix;
    int i ;
    for ( i = *rowz; i > row; --i) {
        *(*matrix+i) = *(*matrix+i - 1);
    }

    int *new_row = (int *)malloc(width * sizeof(int));
    //if (new_row == NULL) exit(787);
    for ( i = 0; i < width; ++i) {
        *(new_row + i) = *(elements + i);
    }

    *(*matrix + row + 1) = new_row;

    int *new_colz = (int *)realloc(*colz, (*rowz + 1) * sizeof(int ));
    //if (new_colz == NULL) exit (555);
    *colz = new_colz;

    for ( i = *rowz; i > row; --i) {
        *(*colz+i) = *(*colz+i - 1);
    }

    *(*colz+row + 1) = width;
    (*rowz)++;
}
void removeRow(int r, int *rowz, int **colz, int ***matrix) {
    if (r >= *rowz) return;

    free(*(*matrix + r));
    *(*matrix + r) = NULL;
    int i;
    for (i = r; i < *rowz - 1; ++i) {
        *(*matrix + i) = *(*matrix + i + 1);
        *(*colz+i) = *(*colz+i + 1);
    }
    (*rowz) --;
    *matrix = (int **)realloc(*matrix, *rowz * sizeof(int *)); //<-?

}

void deleteFirstRow(int *rowz, int **colz, int ***matrix){
    if (*rowz>0) removeRow(0, rowz, colz, matrix);
}
void deleteLastRow(int *rowz, int **colz, int ***matrix){
    if (*rowz >0) removeRow(*rowz -1, rowz, colz, matrix);
}
void swapRows(int r, int s, const int *rowz, int **colz, int ***matrix){
    if (r >= *rowz || s >= *rowz) return;

    int *temp = *(*matrix + r);
    *(*matrix + r) = *(*matrix + s);
    *(*matrix + s) = temp;

    int count = *(*colz + r);
    *(*colz + r) = *(*colz + s);
    *(*colz + s) = count;
}

//------------------------columns-----------------------------
void addFirstColumn(int height, const int *elements, int *rowz, int **colz, int ***matrix) {
    if (height<=0)return;
    if (height > *rowz) {
        *colz = (int *)realloc(*colz, height * sizeof(int ));
        *matrix = (int **)realloc(*matrix, height * sizeof(int *));
    }
    int i = 0;
    for ( i = 0; i < *rowz && i < height; ++i) {
        int newRowSize = *(*colz + i) + 1;
        int *newRow = (int *)realloc(*(*matrix + i), newRowSize * sizeof(int));
        if (newRow) {
            int j;
            for ( j = newRowSize - 1; j > 0; --j) {
                *(newRow+j) = *(newRow+j - 1);
            }
            *newRow = *(elements+i);
            *(*matrix + i) = newRow;
            *(*colz + i) = newRowSize;
        }
       // else exit(778);
    }
    for ( i = *rowz; i < height; ++i) {
        int *newRow = (int *)malloc(sizeof(int));
        if (newRow) {
            *newRow = *(elements+i);
            *(*matrix + i) = newRow;
            *(*colz + i) = 1;
        }
        //else exit(778);
    }
    if (height > *rowz) {
        *rowz = height;
    }
}
void addLastColumn(int height, int *elements, int *rowz, int ** colz, int ***matrix){
    if (height<=0)return;
    int i;
    for ( i = 0; i < *rowz && i < height; ++i) {
        int newRowSize = *(*colz + i) + 1;
        int *newRow = (int *)realloc(*(*matrix + i), newRowSize * sizeof(int));
        if (newRow) {
            *(newRow+newRowSize-1) = *(elements+i);
            *(*matrix + i) = newRow;
            *(*colz + i) = newRowSize;
        }
        //else exit(778);
    }
    for ( i = *rowz; i < height; ++i) {
        int *newRow = (int *)malloc(sizeof(int));
        if (newRow) {
            *newRow = *(elements+i);
            *matrix = (int **)realloc(*matrix, (i + 1) * sizeof(int *));
            *(*matrix + i) = newRow;
            *colz = (int *)realloc(*colz, (i + 1) * sizeof(int ));
            *(*colz + i) = 1;
        }
        //else exit(778);
    }

    if (height > *rowz) {
        *rowz = height;
    }
}
void insertBeforeColumn(int col, int height, int *elements, int *rowz, int **colz, int ***matrix){
    if (height<=0)return;
    int i;
    for ( i = 0; i < *rowz && i < height; ++i) {
        int newRowSize = *(*colz + i) + 1;

        int *newRow = (int *)realloc(*(*matrix+i),newRowSize * sizeof(int));
        if (newRow) {
            if (*(*colz+i) <= col){
                *(newRow+newRowSize-1) = *(elements+i);
                *(*matrix + i) = newRow;
                *(*colz + i) = newRowSize;
            }
            else {
                int j;
                for ( j = newRowSize -1; j > col ; --j) {
                    *(newRow+j) = *(newRow+j - 1);
                }
                *(newRow+col) = *(elements+i);
                *(*matrix + i) = newRow;
                *(*colz + i) = newRowSize;
            }
        }
        //else exit(778);
    }
    for ( i = *rowz; i < height; ++i) {
        int *newRow = (int *)malloc(sizeof(int));
        if (newRow) {
            *newRow = *(elements+i);
            *matrix = (int **)realloc(*matrix, (i + 1) * sizeof(int *));
            *(*matrix + i) = newRow;
            *colz = (int *)realloc(*colz, (i + 1) * sizeof(int ));
            *(*colz + i) = 1;
        }
        //else exit(778);
    }

    if (height > *rowz) {
        *rowz = height;
    }
}
void insertAfterColumn(int col, int height, int *elements, int *rowz, int **colz, int ***matrix){
    if(height<=0)return;
    int i;
    for ( i = 0; i < *rowz && i < height; ++i) {
        int newRowSize = *(*colz + i) + 1;
        int *newRow = (int *)realloc(*(*matrix + i), newRowSize * sizeof(int));
        if (newRow) {
            if (*(*colz+i) <= col){
                *(newRow+newRowSize-1) = *(elements+i);
                *(*matrix + i) = newRow;
                *(*colz + i) = newRowSize;
            }
            else{
                int j;
                for ( j = newRowSize - 1; j > col + 1; --j) {
                    *(newRow+j) = *(newRow+j - 1);
                }
                *(newRow+col + 1) = *(elements+i);
                *(*matrix + i) = newRow;
                *(*colz + i) = newRowSize;
            }
        }
        //else exit(778);
    }
    // Edge case 2: If height >  number of existing rows, add new 1-int rows
    for ( i = *rowz; i < height; ++i) {
        //printf("iteration %d\n", i);
        int *newRow = (int *)malloc(sizeof(int));
        if (newRow) {
            *newRow = *(elements+i);
            *matrix = (int **)realloc(*matrix, (i + 1) * sizeof(int *));
            *(*matrix + i) = newRow;

            *colz = (int *)realloc(*colz, (i + 1) * sizeof(int ));
            *(*colz+i) = 1;

        }
       // else exit(778);
    }
    if (height > *rowz) {
        *rowz = height;
    }
}
void removeColumn(int c, int *rowz, int **colz, int ***matrix) {
    int i;
    for ( i = 0; i < *rowz; ++i) {
       // printf("Row %d, Col %d\n", i, *(*colz + i));
        if (c < *(*colz + i)) {
            int j;
            for (j = c; j < *(*colz + i) - 1; ++j) {
                *(*(*matrix + i) + j) = *(*(*matrix + i) + j + 1);
            }
            if ((*(*colz + i) - 1) > 0) {
                int *newRow = (int *) realloc(*(*matrix + i), (*(*colz + i) - 1) * sizeof(int));
                if (newRow) {
                    *(*matrix + i) = newRow;
                    *(*colz + i) -= 1;
                }
//                else {
//                    free(*(*matrix + i));
//                    *(*matrix + i) = NULL;
//                    exit(778);
//                }
            } else {
                free(*(*matrix + i));
                *(*matrix + i) = NULL;
                *(*colz + i) -= 1;
            }
        }
    }
    i = 0;
    while (i < *rowz) {
        if (*(*colz + i) == 0) {
            removeRow(i, rowz, colz, matrix);
        }
        else i++;
    }
}
void deleteFirstColumn(int *rowz, int **colz, int ***matrix){
    removeColumn(0, rowz, colz, matrix);
}
void deleteLastColumn(int *rowz, int **colz, int ***matrix) {
    int i;
    for ( i = *rowz; i > 0; --i) {
        int lastColIndex = *(*colz + i - 1) - 1;
            removeBlock(i - 1, 1, lastColIndex, 1, rowz, colz, matrix);
    }
}
void swapColumns(int c, int d, const int *rowz, int **colz, int ***matrix){
    int i;
    for ( i = 0; i < *rowz; i++) {
        if (c < *(*colz+i) && d < *(*colz+i)) {
            int temp = *(*(*matrix + i) + c);
            *(*(*matrix + i) + c) = *(*(*matrix + i) + d);
            *(*(*matrix + i) + d) = temp;
        }
    }
}

//--------------------blocks-------------------------


void removeBlock(int r, int h, int c, int w, int * rowz, int ** colz, int*** matrix) {
        if (w<=0 || h <=0) return;
        int i, j, range = *rowz, saved_width = w;
        int** mat_cp = *matrix;
        int * rowSize = *colz;

        if (r + h <= *rowz) range = r + h;

        for (i = r; i < range; i++) {
                w = saved_width;
                if (c + saved_width > *(rowSize + i))
                    w = *(rowSize + i) - c;
                if (*(rowSize + i) >= c + 1) {
                    if (c == 0 && *(rowSize + i) <= w) {

                        free(*(mat_cp + i));
                        *(mat_cp + i) = NULL;
                        for (j = i; j < *rowz - 1; j++) {
                            *(mat_cp + j) = *(mat_cp + j + 1);
                            *(rowSize + j) = *(rowSize + j + 1);
                        }
                        *rowz = *rowz - 1;
                        i--;range--;
                    }
                    else {
                        int* row = (int*)malloc((*(rowSize + i) - w) * sizeof(int));
                        for (j = c; j < *(rowSize + i) - w; j++) {
                            *(*(mat_cp + i) + j) = *(*(mat_cp + i) + j + w);
                        }
                        for (j = 0; j < *(rowSize + i) - w ; j++) {
                            *(row + j) = *(*(mat_cp + i) + j);
                        }
                        free(*(mat_cp + i));
                        *(mat_cp + i) = row;
                        *(rowSize + i) = *(rowSize + i) - w;
                    }
                }
        }
        *matrix = mat_cp;
        *colz = rowSize;
    }

void insertBlock(int r, int c, int h, int w, int **elements,  int *rowzz, int **colzz,int ***matrix) {
    if (w <= 0 || h <= 0) return;
    int** mat_cp = *matrix;
    int * newRowSize = *colzz;
    int rowIdx = *rowzz, i, j;
    int beg = rowIdx, end = rowIdx+h;

    if (r<=*rowzz){beg = r;end = r + h;}

    if (r+h > *rowzz) {
        if (r <= *rowzz) *rowzz = r + h;
        else *rowzz +=h;

        mat_cp = (int **) realloc(mat_cp, (*rowzz) * sizeof(int *));
        newRowSize = (int *) realloc(newRowSize, *rowzz * sizeof(int));
        for (i = rowIdx; i < *rowzz; i++){
            *(mat_cp + i) = (int*) malloc(sizeof (int));
            *(newRowSize + i) = 0;}
    }

    for (i=beg; i < end; i++){
        int requiredRowSize = (*(newRowSize + i) + w> (c + w))? *(newRowSize + i) + w : (c + w);
        *(mat_cp + i)= (int*) realloc(*(mat_cp + i), (requiredRowSize * sizeof (int)));
        if (*(newRowSize + i) - 1 < c){

            for (j= *(newRowSize + i); j < *(newRowSize + i) + w; j++){
                    *(*(mat_cp + i) + j) = *(*(elements + (i - beg)) + (j - *(newRowSize + i))); // add according element
                }
            }
            else {

                for (j = requiredRowSize-1; j > c; j--){
                    if(j-w >=0){
                        *(*(mat_cp + i) + j) = *(*(mat_cp + i) + j - w); //shifting ////////////////////
                    }
                }
                for (j=c; j< c+w; j++){
                    *(*(mat_cp + i) + j) = *(*(elements + (i - beg)) + (j - c)); // = according element
                }
            }
            *(newRowSize + i) = *(newRowSize + i) + w;
    }
    *matrix = mat_cp;
    *colzz = newRowSize;
}

    //---------------------files--------------------


void writeToFile(char* s, int rowz, int* colz, int*** matrix){
    FILE* fileVar = fopen(s, "wb");
    fprintf(fileVar, "%d\n", (unsigned short)rowz);

    if (rowz <=0){
        fclose(fileVar);
        return;
    }

    unsigned char* col = (unsigned char*)malloc(2*sizeof (unsigned char));

    int i, j;
    for (i = 0; i < rowz; i++) {
            //printf("\nwiersz %d: ", i);
            unsigned short num = (unsigned short)*(colz + i);
            //printf("l. el: %d: ", num);
            *col = (unsigned char)(num >> 8);//(co
            *(col+1) = (unsigned char)(num & 0xFF);
            fwrite(col, sizeof(unsigned char), 2, fileVar);

            for (j = 0; j < *(colz + i); j++) {
                int val = *(*(*matrix + i) + j);
                //printf( " %d", val);
                unsigned char *b = (unsigned char *)malloc(4 * sizeof(unsigned char));
                *b = (unsigned char)((val >> 24) & 0xFF);
                *(b+1) = (unsigned char)((val >> 16) & 0xFF);
                *(b+2) = (unsigned char)((val >> 8) & 0xFF);
                *(b+3) = (unsigned char)(val & 0xFF);
                fwrite(b, sizeof(unsigned char), 4, fileVar);
                free(b);
            }
        }

    free(col);
    col = NULL;
    fclose(fileVar);
}

    void readFromFile(const char *filename, int *rowz, int **colz, int ***matrix) {
        FILE *file = fopen(filename, "rb");
        if (file == NULL) return;
        int i, j;

        if (*matrix != NULL) {
            for (i = 0; i < *rowz; i++) {
                free(*((*matrix)+i));
                *((*matrix)+i) = NULL;
            }
            free(*matrix);
            *matrix = NULL;
        }
        if (*colz != NULL) {
            free(*colz);
            *colz = NULL;
        }

        *rowz = 0;

        fscanf(file, "%d\n", rowz);

        *matrix = (int **) malloc(*rowz * sizeof(int *));
        *colz = (int *) malloc(*rowz * sizeof(int));

        for (i = 0; i < *rowz; i++) { //rows
            unsigned char* colz_i = (unsigned char*)malloc(2*sizeof (unsigned char));
            fread(colz_i, sizeof(unsigned char), 2, file);
            *(*colz + i) = ((*colz_i) << 8) | (*(colz_i+1));
            free(colz_i);

            *(*matrix + i) = (int *) malloc(*(*colz + i) * sizeof(int)); //memory for the row

            for (j = 0; j < *(*colz + i); j++) {
                unsigned char *b = (unsigned char *) malloc(4 * sizeof(unsigned char));
                fread(b, sizeof(unsigned char), 4, file);
                int val = ((*b) << 24) | ((*(b+1)) << 16) | ((*(b+2)) << 8) | (*(b+3));
                *(*(*matrix + i) + j) = val;
                free(b);
            }
        }
        fclose(file);
    }

//----------------special---------------------------
    void print(int rowzz, const int *colzz, int ***matrix) {
        int i, k;
        printf("%hu\n", (unsigned short)rowzz);
        for (i = 0; i < rowzz; i++) {
            printf("%hu ", (unsigned short)*(colzz + i)); //<- elements in the row

            for (k = 0; k < *(colzz + i); k++) {
                printf("%d ", *(*(*matrix + i) + k));
            }
            printf("\n");
        }
    }
    void end(const int *rowzz, int **colzz, int ***matrix) {
        int i;
        for (i = 0; i < *rowzz; i++) {
            free(*(*matrix + i));
        }
        free(*matrix);
        *matrix = NULL;

        free(*colzz);
        *colzz = NULL;
    }


    int main() {
        char *code = (char*)malloc(4 * sizeof(char));
        strcpy(code, "000");

        char *filename = (char*)malloc(16 * sizeof(char));
        unsigned short r, col, w, d, s, h, i, j;
        int rowz = 0;

        int **matrix = (int**) malloc(sizeof (int*));
        //*matrix = (int*) malloc(sizeof (int));
        int *colz = (int *)malloc(sizeof (int ));
        *colz = 0;

        while (strcmp(code, "END") != 0) {
            scanf(" %3s", code);
            //printf("Code: %s\n", code);
            if (strcmp(code, "AFR") == 0) {
                scanf(" %hu", &w);
                int *elements = (int *) malloc(w * sizeof(int));


                for (i = 0; i < w; i++) {
                    scanf(" %d", elements + i);
                }
                addFirstRow(w, elements, &rowz, &colz, &matrix);
                free(elements);
                elements = NULL;
            } else if (strcmp(code, "ALR") == 0) {
                scanf(" %hu", &w);
                int *elements = (int *) malloc(w * sizeof(int));

                for (i = 0; i < w; i++) {
                    scanf(" %d", elements + i);
                }
                addLastRow(w, elements, &rowz, &colz, &matrix);
                free(elements);
                elements = NULL;
            } else if (strcmp(code, "AFC") == 0) {
                scanf(" %hu", &h);
                int *elements = (int *) malloc(h * sizeof(int));

                for (i = 0; i < h; i++) {
                    scanf(" %d", elements + i);
                }
                addFirstColumn(h, elements, &rowz, &colz, &matrix);
                free(elements);
                elements = NULL;
            } else if (strcmp(code, "ALC") == 0) {
                scanf(" %hu", &h);
                int *elements = (int *) malloc(h * sizeof(int));

                for (i = 0; i < h; i++) {
                    scanf(" %d", elements + i);
                }
                addLastColumn(h, elements, &rowz, &colz, &matrix);
                free(elements);
                elements = NULL;
            } else if (strcmp(code, "IBR") == 0) {
                scanf(" %hu %hu", &r, &w);

                int *elements = (int *) malloc(w * sizeof(int));
                for (i = 0; i < w; i++) {
                    scanf(" %d", elements + i);
                }
                insertBeforeRow(r, w, elements, &rowz, &colz, &matrix);
                free(elements);
                elements = NULL;
            } else if (strcmp(code, "IAR") == 0) {
                scanf(" %hu %hu", &r, &w);

                int *elements = (int *) malloc(w * sizeof(int));
                for (i = 0; i < w; i++) {
                    scanf(" %d", elements + i);
                }
                insertAfterRow(r, w, elements, &rowz, &colz, &matrix);
                free(elements);
                elements = NULL;
            } else if (strcmp(code, "IBC") == 0) {
                scanf(" %hu %hu", &col, &h);

                int *elements = (int *) malloc(h * sizeof(int));

                for (i = 0; i < h; i++) {
                    scanf(" %d", elements + i);
                }
                insertBeforeColumn(col, h, elements, &rowz, &colz, &matrix);
                free(elements);
                elements = NULL;
            } else if (strcmp(code, "IAC") == 0) {
                scanf(" %hu %hu", &col, &h);

                int *elements = (int *) malloc(h * sizeof(int));
                for (i = 0; i < h; i++) {
                    scanf(" %d", elements + i);
                }
                insertAfterColumn(col, h, elements, &rowz, &colz, &matrix);
                free(elements);
                elements = NULL;
            } else if (strcmp(code, "SWR") == 0) {
                scanf(" %hu %hu", &r, &s);
                swapRows(r, s, &rowz, &colz, &matrix);
            } else if (strcmp(code, "SWC") == 0) {
                scanf(" %hu %hu", &col, &d);
                swapColumns(col, d, &rowz, &colz, &matrix);
            } else if (strcmp(code, "DFR") == 0) {
                deleteFirstRow(&rowz, &colz, &matrix);
            } else if (strcmp(code, "DLR") == 0) {
                deleteLastRow(&rowz, &colz, &matrix);
            } else if (strcmp(code, "DFC") == 0) {
                deleteFirstColumn(&rowz, &colz, &matrix);
            } else if (strcmp(code, "DLC") == 0) {
                deleteLastColumn(&rowz, &colz, &matrix);
            } else if (strcmp(code, "RMR") == 0) {
                scanf(" %hu", &r);
                removeRow((int)r, &rowz, &colz, &matrix);
            } else if (strcmp(code, "RMC") == 0) {
                scanf(" %hu", &col);
                removeColumn((int)col, &rowz, &colz, &matrix);
            } else if (strcmp(code, "RMB") == 0) {
                scanf(" %hu %hu %hu %hu", &r, &h, &col, &w);
                removeBlock((int)r, (int)h, (int)col, (int)w, &rowz, &colz, &matrix);
            } else if (strcmp(code, "ISB") == 0) {
                scanf(" %hu %hu %hu %hu", &r, &col, &h, &w);
                int **elements = (int **) malloc(h * sizeof(int *));

                //printf("r: %hu, h: %hu, col: %hu, w: %hu\n", r, h, col, w);
                for (i = 0; i < h; i++) {
                    *(elements + i) = (int *) malloc(w * sizeof(int));
                    for (j = 0; j < w; j++) {
                        scanf("%d", *(elements + i) + j);
                    }
                }

                insertBlock((int)r, (int)col, (int)h, (int)w, elements, &rowz, &colz, &matrix);
                for (i = 0; i < h; i++) {
                    free(*(elements + i));
                }
                free(elements);
                elements = NULL;
            } else if (strcmp(code, "WRF") == 0) {
                scanf(" %15s", filename);
                writeToFile(filename, rowz,colz, &matrix);
            } else if (strcmp(code, "RDF") == 0) {
                scanf(" %15s", filename);
                readFromFile(filename, &rowz, &colz, &matrix);
            } else if (strcmp(code, "PRT") == 0) {
                print(rowz, colz, &matrix);
            }
        }
        free(code);
        code = NULL;
        free(filename);
        filename=NULL;
        end(&rowz, &colz, &matrix);
        return 0;
    }
