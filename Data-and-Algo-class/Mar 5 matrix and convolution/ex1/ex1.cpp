#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Create a Matrix of 4 rows and 4 columns
const int MATRIX_SIZE = 4;


//Initialize the Matrix with random value from 0 to 99 (initializeMatrix)
void initializeMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    srand(time(nullptr));
    for (int i=0; i<MATRIX_SIZE; ++i) {
        for (int j=0; j<MATRIX_SIZE; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
}



//Write a function to show values in diagonal of the matrix
void diagonalValue(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    cout << "Diagonal elements: ";
    for (int i=0; i<MATRIX_SIZE; ++i) {
        cout << matrix[i][i] << " ";
    }
    cout << endl;
}

//Write a function to sum all values of each row
void sumRow(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i=0; i<MATRIX_SIZE; ++i) {
        int rowSum =0;
        for (int j=0; j<MATRIX_SIZE; ++j) {
            rowSum += matrix[i][j];
        }
    cout << "Sum of row: " << i + 1 << ": " << rowSum << endl;
    }
    
}

//Write a function to sum all value of each column
void sumCol(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int j=0; j<MATRIX_SIZE; ++j) {
        int colSum = 0; 
        for (int i=0; i<MATRIX_SIZE; ++i) {
            colSum += matrix[j][i];
        }
    cout << "Sum of col: " << j + 1 << ": " << colSum << endl; 
    }
}


//Write a function to find highest value in the Matrix
int highestValue(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    int highest = matrix[0][0];
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            if (matrix[i][j] > highest) {
                highest = matrix[i][j];
            }

        }
    }
    return highest;
}


//Write a function to sum all items of the matrix which value is divisible by 3 or 7
int sumDivisible3or7(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    int sum = 0; 
    for (int i=0; i<MATRIX_SIZE; ++i) {
        for (int j=0; j<MATRIX_SIZE; ++j) {
            if (matrix[i][j] % 3 == 0 || matrix[i][j] % 7 == 0) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}


//Write a function to mirror the matrix
void mirrorMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]){
    for (int i=0; i<MATRIX_SIZE; ++i) {
        for (int j=0; j<MATRIX_SIZE/2; ++j) {
            swap(matrix[i][j], matrix[i][MATRIX_SIZE-1-j]);
        }
    }
}

int main() {
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    initializeMatrix(matrix);

    cout << "Origianl matrix: " << endl;
    for (int i=0; i<MATRIX_SIZE; ++i) {
        for (int j=0; j<MATRIX_SIZE; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl; 
    }
    diagonalValue(matrix);
    sumRow(matrix);
    sumCol(matrix);
    cout << "Highest value: " << highestValue(matrix) << endl;
    cout << "Sum divisible by 3 or 7: " << sumDivisible3or7(matrix) << endl; 

    mirrorMatrix(matrix);
    cout << "Mirrored matrix: " << endl;
    for (int i=0; i<MATRIX_SIZE; ++i) {
        for (int j=0; j<MATRIX_SIZE; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl; 
    }
    return 0;
}

