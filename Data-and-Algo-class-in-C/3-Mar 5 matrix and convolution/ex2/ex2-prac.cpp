/*
write c program to Create a Matrix of 28 rows x 28 column. Then Initialize the Matrix with random value of 0 or 1. Next add a function to calculate convolution on that matrix using the convolution kernel given below.
Stride Length = 1
Kernel
1 0 1
0 1 0
1 0 1
// Then add function to calculate max pooling on that matrix returned by convolutional function. Stride Length = 1. Pooling dimension 3x3. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 28
#define COLS 28

// Function to initialize the matrix with random 0s and 1s
void initializeMatrix(int matrix[ROWS][COLS]) {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = rand() % 2; // Generate random 0 or 1
        }
    }
}

// Assuming the kernel is a 3x3 matrix
#define KERNEL_SIZE 3

// Function to perform convolution
void performConvolution(int inputMatrix[ROWS][COLS], int outputMatrix[ROWS][COLS]) {
    int kernel[KERNEL_SIZE][KERNEL_SIZE] = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    // Apply convolution
    for (int i = 1; i < ROWS - 1; ++i) {
        for (int j = 1; j < COLS - 1; ++j) {
            int sum = 0;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    sum += inputMatrix[i + x][j + y] * kernel[x + 1][y + 1];
                }
            }
            outputMatrix[i][j] = sum;
        }
    }
}

// Function to perform max pooling
void performMaxPooling(int inputMatrix[ROWS][COLS], int pooledMatrix[ROWS/3][COLS/3]) {
    for (int i = 0; i < ROWS; i += 3) {
        for (int j = 0; j < COLS; j += 3) {
            int maxVal = inputMatrix[i][j];
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    maxVal = (inputMatrix[i + x][j + y] > maxVal) ? inputMatrix[i + x][j + y] : maxVal;
                }
            }
            pooledMatrix[i/3][j/3] = maxVal;
        }
    }
}


int main() {
    int matrix[ROWS][COLS];
    initializeMatrix(matrix);

    // Print the matrix (optional)
    printf("Initialized Matrix:\n");
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    int inputMatrix[ROWS][COLS];
    initializeMatrix(inputMatrix);

    int outputMatrix[ROWS][COLS];

    // Perform convolution
    performConvolution(inputMatrix, outputMatrix);

    int pooledMatrix[ROWS/3][COLS/3];


    // Perform max pooling
    performMaxPooling(outputMatrix, pooledMatrix);

    // Print the pooled matrix
    printf("Pooled Matrix after max pooling:\n");
    for (int i = 0; i < ROWS/3; ++i) {
        for (int j = 0; j < COLS/3; ++j) {
            printf("%d ", pooledMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
