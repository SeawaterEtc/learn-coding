//write c program to Create a Matrix of 4 rows and 4 column.
//Then Initialize the Matrix with random value from 0 to 99.
//function to show values in diagonal of the matrix
//function to sum all values of each row
//function to sum all value of each column
//function to find highest value in the Matrix
//function to sum all items of the matrix which value is divisible by 3 or 7
//function to mirror the matrix

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the diagonal elements of the matrix
void displayDiagonal(int matrix[4][4]) {
    printf("Diagonal elements: ");
    for (int i = 0; i < 4; ++i) {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
}

// Function to calculate the sum of each row
void sumRows(int matrix[4][4]) {
    printf("Sum of each row:\n");
    for (int i = 0; i < 4; ++i) {
        int rowSum = 0;
        for (int j = 0; j < 4; ++j) {
            rowSum += matrix[i][j];
        }
        printf("Row %d: %d\n", i + 1, rowSum);
    }
}

// Function to calculate the sum of each column
void sumColumns(int matrix[4][4]) {
    printf("Sum of each column:\n");
    for (int j = 0; j < 4; ++j) {
        int colSum = 0;
        for (int i = 0; i < 4; ++i) {
            colSum += matrix[i][j];
        }
        printf("Column %d: %d\n", j + 1, colSum);
    }
}

// Function to find the highest value in the matrix
int findHighestValue(int matrix[4][4]) {
    int highest = matrix[0][0];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (matrix[i][j] > highest) {
                highest = matrix[i][j];
            }
        }
    }
    return highest;
}

// Function to sum items divisible by 3 or 7
int sumDivisibleBy3Or7(int matrix[4][4]) {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (matrix[i][j] % 3 == 0 || matrix[i][j] % 7 == 0) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

// Function to mirror the matrix
void mirrorMatrix(int matrix[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][3 - j];
            matrix[i][3 - j] = temp;
        }
    }
}

int main() {
    srand(time(NULL));
    int matrix[4][4];

    // Initialize the matrix with random values
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    displayDiagonal(matrix);
    sumRows(matrix);
    sumColumns(matrix);
    printf("Highest value in the matrix: %d\n", findHighestValue(matrix));
    printf("Sum of items divisible by 3 or 7: %d\n", sumDivisibleBy3Or7(matrix));

    mirrorMatrix(matrix);
    printf("Mirrored Matrix:\n");
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
