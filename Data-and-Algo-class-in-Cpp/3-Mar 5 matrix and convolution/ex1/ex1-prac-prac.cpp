// Create a Matrix of 4 rows and 4 column
//Initialize the Matrix with random value from 0 to 99
//Write a function to show values in diagonal of the matrix
//Write a function to sum all values of each row
//Write a function to sum all value of each column
//Write a function to find highest value in the Matrix
//Write a function to sum all items of the matrix which value is divisible by 3 or 7
//Write a function to mirror the matrix


#include <iostream>
#include <cstdlib>
#include <ctime>
// <iostream>: Provides input/output functionalities (e.g., printing to the console).
// <cstdlib>: Provides functions for random number generation (rand()) and integer conversions (std::swap).
// <ctime>: Provides functions for time manipulation (time(nullptr)) used for seeding the random number generator.

using namespace std;
// without using std

const int MATRIX_SIZE = 4;
//Defines a constant named MATRIX_SIZE with a value of 4, representing the size of the square matrix.


// Function to initialize the matrix with random values from 0 to 99
//8-13 (initializeMatrix Function):
void initializeMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    //Seeds the random number generator using srand(time(nullptr)).
    srand(time(nullptr));
    //Uses nested for loops to iterate through each row (i) and column (j) of the matrix.
    for (int i=0; i<MATRIX_SIZE; ++i) {
        for (int j=0; j<MATRIX_SIZE; ++j) {
            matrix[i][j] = rand() % 100;

        }
    }
        //Assigns a random value between 0 and 99 (inclusive) to each element matrix[i][j] using rand() % 100.

};

// Function to display the diagonal elements of the matrix
//15-20 (displayDiagonal Function):
void displayDiagonal(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    //Prints "Diagonal elements: " to the console.
    cout << "Diagonal elements: ";
    //Uses a loop to iterate through the diagonal elements (i == j).
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        //Prints the value at matrix[i][i] followed by a space for each element on the diagonal.
        cout << matrix[i][i] << " ";
    }
        //Prints a newline character (endl).
    cout << endl;
}

// Function to sum the values of each row
//22-30 (sumRows Function):
void sumRows(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    //Uses a loop to iterate through each row (i).
    for (int i=0; i < MATRIX_SIZE; ++i) {
        //Initializes a variable rowSum to 0 to store the cumulative sum for the current row.
        int rowSum = 0;
        //Uses a nested loop to iterate through each element (j) in the current row.
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            //Adds the value at matrix[i][j] to rowSum.
            rowSum += matrix[i][j];
        }
    //Prints "Sum of row X: Y", where X is the row number (1-based indexing) and Y is the calculated rowSum.
    cout << "Sum of row: " << i + 1 << ": " << rowSum << endl;
    }

}


// Function to sum the values of each column (sumColumns)
void sumColumns(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    //Uses a loop to iterate through each column (j).
    for (int j = 0; j < MATRIX_SIZE; ++j) {
        //Initializes a variable colSum to 0 to store the cumulative sum for the current column.
        int colSum = 0;
        //Uses a nested loop to iterate through each element (i) in the current column.
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            //Adds the value at matrix[i][j] to colSum.
            colSum += matrix[j][i];
        }
    //Prints "Sum of column X: Y", where X is the column number (1-based indexing) and Y is the calculated colSum.
    cout << "Sum of column: " << j + 1 << ": " << colSum << endl;
    }
}

// Function to find the highest value in the matrix (findHighestValue)
int findHighestValue(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    //Initializes a variable highest with the value at matrix[0][0].
    int highest = matrix[0][0];
    //Uses nested loops to iterate through all elements of the matrix.
    for (int i=0; i<MATRIX_SIZE; ++i) {
        for (int j=0; j<MATRIX_SIZE; ++j) { \
            //Compares the current element matrix[i][j] with the current highest value. If the current element is greater, updates highest with the new value.
            if (matrix[i][j] > highest) {
                highest = matrix[i][j];
            }

        }

    }
    //Returns the final highest value, which represents the highest element in the matrix.
    return highest;
}



// Function to sum items divisible by 3 or 7
int sumNumDivisible3or7(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    //Initializes a variable sum to 0 to store the cumulative sum of divisible elements.
    int sum = 0;
    //Uses nested loops to iterate through all elements of the matrix.
    for (int i=0; i<MATRIX_SIZE; ++i) {
        for (int j=0; j<MATRIX_SIZE; ++j) {
            //Checks if the current element matrix[i][j] is divisible by 3 or 7 using the modulo operator (%) If divisible (matrix[i][j] % 3 == 0 || matrix[i][j] % 7 == 0), adds the element's value to sum.
            if (matrix[i][j] % 7 == 0 || matrix[i][j] % 3 == 0) {
                sum += matrix[i][j];
            }
        }
    }
        //Returns the final sum, which represents the sum of elements divisible by 3 or 7.
    return sum;
}

// Function to mirror the matrix void mirrorMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]): Defines a function named mirrorMatrix that takes a 2D integer array (matrix) as input and doesn't return a value (void).
void mirrorMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i=0; i < MATRIX_SIZE; ++i) {
        for (int j=0; j < MATRIX_SIZE / 2; ++j) {
            swap(matrix[i][j], matrix[i][MATRIX_SIZE - 1 - j]);
        }
    }
}


//int main() 
int main () {
    // Matrix Creation and Initialization: int matrix[MATRIX_SIZE][MATRIX_SIZE];: Declares a 2D integer array named matrix with dimensions MATRIX_SIZE x MATRIX_SIZE.
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    // initializeMatrix(matrix);: Calls the initializeMatrix function (presumably defined elsewhere) to fill the matrix with random values.
    initializeMatrix(matrix);


    // Display original matrix
    cout << "Original matrix: " << endl; 
    // Prints a label "Original Matrix:" to the console.
    // Uses nested loops to print each element of the matrix in a grid format.
    for (int i=0; i<MATRIX_SIZE; ++i) {
        for (int j=0; j<MATRIX_SIZE; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    // Calls functions like displayDiagonal, sumRows, sumColumns, findHighestValue, and sumDivisibleBy3Or7 (presumably defined elsewhere) to work with the matrix.
    displayDiagonal(matrix);
    sumRows(matrix);
    sumColumns(matrix);
    cout << "Highest: " << findHighestValue(matrix) << endl;
    cout << "Sum divisible 7 or 3: " << sumNumDivisible3or7(matrix) << endl; 


    // Mirror the matrix
    // mirrorMatrix(matrix);: Calls the mirrorMatrix function to flip the matrix vertically.
    mirrorMatrix(matrix);
    cout << "mirrored Matrix: " << endl;
    for (int i =0; i<MATRIX_SIZE; ++i) {
        for (int j=0; j<MATRIX_SIZE; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0; 

}
