#include <stdio.h>

void PrintMatrix(int matrix[5][5], int s_row, int s_col){
    for (int i=s_row; i<s_row+3; i++){
        for (int j=s_col; j<s_col+3; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
}

void SlicingWindow(int matrix[5][5]){
    for (int i=0; i<5-2; i++){
        for (int j=0; j<5-2; j++){
           PrintMatrix(matrix, i, j);
           printf("\n");
        }
        printf("\n");
    }
}


int main(){
    printf("The original matrix is: \n");
    int matrix[5][5] = {{1,0,1,0,1},
                        {0,1,0,1,0},
                        {1,1,1,1,1},
                        {0,1,0,1,0},
                        {0,0,0,0,0}};
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    SlicingWindow(matrix);
}