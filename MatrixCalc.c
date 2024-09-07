#include <stdio.h>
/*
    Matrix Calculator
*/
#define GUIMAX 70

//title
void title(){
    printf("\033[0;32m"); //define green color
    printf("                                                                                       \n");
    printf("o     o         o        o        .oPYo.       8              8         o              \n");
    printf("8b   d8         8                 8    8       8              8         8              \n");
    printf("8`b d'8 .oPYo. o8P oPYo.o8`o  o'  8     .oPYo. 8 .oPYo.o    o 8 .oPYo. o8P.oPYo. oPYo.\n");
    printf("8 `o' 8 .oooo8  8  8  `' 8 `bd'   8     .oooo8 8 8    '8    8 8 .oooo8  8 8    8 8  `' \n");
    printf("8     8 8    8  8  8     8 d'`b   8    88    8 8 8    .8    8 8 8    8  8 8    8 8     \n");
    printf("8     8 `YooP8  8  8     8o'  `o  `YooP'`YooP8 8 `YooP'`YooP' 8 `YooP8  8 `YooP' 8     \n");
    printf("..::::..:.....::..:..::::...:::..::.....:.....:..:.....:.....:..:.....::..:.....:..::::\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf(":::::::::::::::::::::::::::::::::::::\033[7m by JV \033[0;32m:::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\033[0m"); //reset color
}

//Interface
void create_topLine(){

    printf("\033[0;34m%c", 201);
    for(int i=0; i<GUIMAX; i++){
        printf("%c", 205);
    }
    printf("%c", 187);
}

void create_sideLine(char string[], int tam){

    printf("%c\033[0m\t\t%s", 186, string);
    int total = GUIMAX - tam - 15;
    for(int i=0; i<total; i++)
        printf(" ");
    printf("\033[0;34m%c", 186);
}

void create_bottomLine(){

    printf("%c", 200);
    for(int i=0; i<GUIMAX; i++){
        printf("%c", 205);
    }
    printf("%c\033[0m", 188);
}

//Creation Matrix
void define_index(int *r, int *c){

    printf("\nRows: ");
    scanf("%d", &*r);
    printf("\nColumns: ");
    scanf("%d", &*c);
}

void write_matrix(int r, int c, float matrix[r][c]){

    printf("\n");
    create_topLine();
    printf("\n");
    //printf("\n\t\tWrite the values for each position below\n");
    create_sideLine("Write the values for each position below", 40);
    printf("\n");
    create_bottomLine();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("\n(%d,%d): ", i+1, j+1);
            scanf("%f", &matrix[i][j]);
        }
    }
}

void print_matrix(int r, int c, float matrix[r][c]){

    printf("\n");
    for(int i=0; i<r; i++){
        printf("\t\t\t\033[0;32m|");
        for(int j=0; j<c; j++){
            printf("  %.1f", matrix[i][j]);
        }
        printf(" |\033[0m\n\n");
    }
}

//Operations
void transposed_matrix(int r, int c, float matrix[r][c], float transposed[c][r]){

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            transposed[i][j] = matrix[j][i];
        }
    }
}

//Main
int main(){


    title();

    int rows, columns;

    define_index(&rows, &columns);

    float matrix[rows][columns];


    write_matrix(rows, columns, matrix);
    printf("\n\t\t\t\t\033[0;32mMATRIX\033[0m\n");
    print_matrix(rows, columns, matrix);

    int op;
    printf("\n1 - Transposed\n2 - Inverse\n");
    printf("\nWhat operation do you want to perform? : ");
    scanf("%d", &op);
    switch(op)
    {
    case 1:{
        float transposed[columns][rows];
        transposed_matrix(rows, columns, matrix, transposed);

        printf("\n\tTRANSPOSED MATRIX:\n");
        print_matrix(columns, rows, transposed);
        break;
    }
    case 2:
        break;

    default :
        printf("\nInvalid Option!\n");
        break;
    }



    //float det = determinant_matrix(order, matrix);
    return 0;
}
