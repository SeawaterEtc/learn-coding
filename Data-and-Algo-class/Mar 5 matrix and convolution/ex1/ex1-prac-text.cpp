// Create a Matrix of 4 rows and 4 column
//Initialize the Matrix with random value from 0 to 99
//Write a function to show values in diagonal of the matrix
//Write a function to sum all values of each row
//Write a function to sum all value of each column
//Write a function to find highest value in the Matrix
//Write a function to sum all items of the matrix which value is divisible by 3 or 7
//Write a function to mirror the matrix

// <iostream>: Provides input/output functionalities (e.g., printing to the console).
// <cstdlib>: Provides functions for random number generation (rand()) and integer conversions (std::swap).
// <ctime>: Provides functions for time manipulation (time(nullptr)) used for seeding the random number generator.


// without using std

//Defines a constant named MATRIX_SIZE with a value of 4, representing the size of the square matrix.


// Function to initialize the matrix with random values from 0 to 99
//8-13 (initializeMatrix Function):
    //Seeds the random number generator using srand(time(nullptr)).
    //Uses nested for loops to iterate through each row (i) and column (j) of the matrix.
        //Assigns a random value between 0 and 99 (inclusive) to each element matrix[i][j] using rand() % 100.

// Function to display the diagonal elements of the matrix
//15-20 (displayDiagonal Function):
    //Prints "Diagonal elements: " to the console.
    //Uses a loop to iterate through the diagonal elements (i == j).
        //Prints the value at matrix[i][i] followed by a space for each element on the diagonal.
    //Prints a newline character (endl).


// Function to sum the values of each row
//22-30 (sumRows Function):
    //Uses a loop to iterate through each row (i).
        //Initializes a variable rowSum to 0 to store the cumulative sum for the current row.
        //Uses a nested loop to iterate through each element (j) in the current row.
            //Adds the value at matrix[i][j] to rowSum.
    //Prints "Sum of row X: Y", where X is the row number (1-based indexing) and Y is the calculated rowSum.


// Function to sum the values of each column (sumColumns)
    //Uses a loop to iterate through each column (j).
        //Initializes a variable colSum to 0 to store the cumulative sum for the current column.
        //Uses a nested loop to iterate through each element (i) in the current column.
            //Adds the value at matrix[i][j] to colSum.
    //Prints "Sum of column X: Y", where X is the column number (1-based indexing) and Y is the calculated colSum.


// Function to find the highest value in the matrix (findHighestValue)
    //Initializes a variable highest with the value at matrix[0][0].
    //Uses nested loops to iterate through all elements of the matrix.
        //Compares the current element matrix[i][j] with the current highest value. If the current element is greater, updates highest with the new value.
    //Returns the final highest value, which represents the highest element in the matrix.




// Function to sum items divisible by 3 or 7
    //Initializes a variable sum to 0 to store the cumulative sum of divisible elements.
    //Uses nested loops to iterate through all elements of the matrix.
        //Checks if the current element matrix[i][j] is divisible by 3 or 7 using the modulo operator (%).
            //If divisible (matrix[i][j] % 3 == 0 || matrix[i][j] % 7 == 0), adds the element's value to sum.
    //Returns the final sum, which represents the sum of elements divisible by 3 or 7.


// Function to mirror the matrix
//void mirrorMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]): Defines a function named mirrorMatrix that takes a 2D integer array (matrix) as input and doesn't return a value (void).
    //Looping through Rows: for (int i = 0; i < MATRIX_SIZE; ++i): Iterates through each row of the matrix (index i).
        //Swapping Elements within a Row: for (int j = 0; j < MATRIX_SIZE / 2; ++j): Iterates through half of the columns in the current row (index j). This is because mirroring involves swapping elements that are symmetric across the vertical center.
            // sswap(matrix[i][j], matrix[i][MATRIX_SIZE - 1 - j]): Swaps the values at two positions in the current row: //matrix[i][j]: The element at the current column index j. matrix[i][MATRIX_SIZE - 1 - j]: The element at the corresponding mirrored position in the same row, calculated as MATRIX_SIZE - 1 - j.

//int main() 
    // Matrix Creation and Initialization: int matrix[MATRIX_SIZE][MATRIX_SIZE];: Declares a 2D integer array named matrix with dimensions MATRIX_SIZE x MATRIX_SIZE.
    // initializeMatrix(matrix);: Calls the initializeMatrix function (presumably defined elsewhere) to fill the matrix with random values.


    // Display original matrix
    // Prints a label "Original Matrix:" to the console.
    // Uses nested loops to print each element of the matrix in a grid format.


    // Calls functions like displayDiagonal, sumRows, sumColumns, findHighestValue, and sumDivisibleBy3Or7 (presumably defined elsewhere) to work with the matrix.


    // Mirror the matrix
    // mirrorMatrix(matrix);: Calls the mirrorMatrix function to flip the matrix vertically.


