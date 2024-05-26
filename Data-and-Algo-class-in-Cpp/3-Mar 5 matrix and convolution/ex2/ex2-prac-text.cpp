#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
/*
1-4: Include Statements:
<iostream>: Provides input/output functionalities (e.g., printing to the console).
<vector>: Provides functionalities for working with vectors (used for the matrix representation).
<cstdlib>: Provides functions for random number generation (rand()).
<ctime>: Provides functions for time manipulation (time(nullptr)) used for seeding the random number generator.
5: Using namespace std:
Avoids repeatedly writing std:: before standard library elements (e.g., std::cout, std::vector).
*/
const int MATRIX_SIZE = 28;
const vector<vector<int>> KERNEL = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
const int KERNEL_SIZE = 3;
const int POOL_SIZE = 3;
/*
Constants:
MATRIX_SIZE: Defines the size of the square matrix (28x28).
KERNEL: Defines the 3x3 convolution kernel as a 2D vector of vectors.
KERNEL_SIZE: Defines the size of the kernel (3).
POOL_SIZE: Defines the size of the pooling window (3).

*/
// Function to initialize the matrix with random values of 0 or 1
void initializeMatrix(vector<vector<int>>& matrix) {
    srand(time(nullptr));
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            matrix[i][j] = rand() % 2;
        }
    }
}
/*
11-20 (initializeMatrix Function):

This function initializes the matrix with random values (0 or 1):
srand(time(nullptr)): Seeds the random number generator for generating unbiased random values.
Nested for loops to iterate through each row (i) and column (j) of the matrix.
matrix[i][j] = rand() % 2: Assigns a random value 0 or 1 (using the modulo operator %) to each element of the matrix.
*/
// Function to perform convolution on the matrix
vector<vector<int>> convolution(const vector<vector<int>>& matrix) {
    int convSize = MATRIX_SIZE - KERNEL_SIZE + 1;
    vector<vector<int>> convMatrix(convSize, vector<int>(convSize, 0));

    for (int i = 0; i <= MATRIX_SIZE - KERNEL_SIZE; ++i) {
        for (int j = 0; j <= MATRIX_SIZE - KERNEL_SIZE; ++j) {
            for (int ki = 0; ki < KERNEL_SIZE; ++ki) {
                for (int kj = 0; kj < KERNEL_SIZE; ++kj) {
                    convMatrix[i][j] += matrix[i + ki][j + kj] * KERNEL[ki][kj];
                }
            }
        }
    }

    return convMatrix;
}
/*
22-47 (convolution Function):This function performs convolution on the matrix using the defined kernel:
    convSize: Calculates the output size of the convolution operation, considering the kernel size and stride (assumed to be 1).
    convMatrix: Initializes a 2D vector to store the convolution result with the calculated size.

    Nested for loops to iterate through possible starting positions for the kernel in the input matrix (i <= MATRIX_SIZE - KERNEL_SIZE and j <= MATRIX_SIZE - KERNEL_SIZE).
                    Inner nested for loops to iterate through elements within the kernel size (ki and kj).convMatrix[i][j] += matrix[i + ki][j + kj] * KERNEL[ki][kj]: Performs the element-wise multiplication between the corresponding elements in the kernel and the input matrix, accumulating the sum in the convolution matrix at position [i][j].
    Returns the convMatrix containing the convolution result.

*/
// Function to perform max pooling on the matrix
vector<vector<int>> maxPooling(const vector<vector<int>>& matrix) {
    int pooledSize = matrix.size() - POOL_SIZE + 1;
    vector<vector<int>> pooledMatrix(pooledSize, vector<int>(pooledSize, 0));

    for (int i = 0; i <= matrix.size() - POOL_SIZE; ++i) {
        for (int j = 0; j <= matrix[0].size() - POOL_SIZE; ++j) {
            int maxVal = 0;
            for (int pi = 0; pi < POOL_SIZE; ++pi) {
                for (int pj = 0; pj < POOL_SIZE; ++pj) {
                    maxVal = max(maxVal, matrix[i + pi][j + pj]);
                }
            }
            pooledMatrix[i][j] = maxVal;
        }
    }

    return pooledMatrix;
}
/*
49-74 (maxPooling Function):
This function performs max pooling on the matrix:
pooledSize: Calculates the output size of the max pooling operation, considering the pooling window size and stride (assumed to be 1).
pooledMatrix: Initializes a 2D vector to store the max pooling result with the calculated size.
Nested for loops to iterate through possible starting positions for the pooling window in the input matrix (i <= matrix.size() - POOL_SIZE and j <= matrix[0].size() - POOL_SIZE). This considers both rows and columns of the matrix.
Initializes maxVal to 0 to store the current maximum value within the pooling window.
Inner nested for loops to iterate through elements within the pooling window size (pi and pj).
maxVal = max(maxVal, matrix[i + pi][j + pj]): Compares the current element in the window (matrix[i + pi][j + pj]) with the maxVal. Updates maxVal if the current element is greater.
After iterating through the window, sets the corresponding element in pooledMatrix[i][j] to the final maxVal.
Returns the pooledMatrix containing the max pooling result.
*/
// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
/*
(printMatrix Function): This function prints the contents of a matrix (optional, used for visualization):
    Iterates through each row (row) in the matrix.
        Iterates through each element (val) in the current row.
            Prints the element value followed by a space.
    Prints a newline character (endl) after each row.
*/




int main() {
    // Step 1: Create and initialize the matrix
    vector<vector<int>> matrix(MATRIX_SIZE, vector<int>(MATRIX_SIZE));
    initializeMatrix(matrix);
    
    // Optionally, print the initialized matrix
    //printMatrix(matrix);

    // Step 2: Perform convolution
    auto convMatrix = convolution(matrix);
    cout << "Convolution Result:" << endl;
    printMatrix(convMatrix);

    // Step 3: Perform max pooling
    auto pooledMatrix = maxPooling(convMatrix);
    cout << "Max Pooling Result:" << endl;
    printMatrix(pooledMatrix);

    return 0;
}

/* vector<vector<int>> matrix(MATRIX_SIZE, vector<int>(MATRIX_SIZE)); This line creates a 2D vector named matrix to represent the image data.
vector<vector<int>>: This syntax defines a 2D vector. The outer vector stores rows, and each inner vector represents a column.
matrix(MATRIX_SIZE, vector<int>(MATRIX_SIZE)): This initializes the matrix with MATRIX_SIZE rows. Each row is further initialized as a vector of integers with MATRIX_SIZE elements, resulting in a square matrix of the desired size (28x28 in this case).
6: initializeMatrix(matrix);

This line calls the initializeMatrix function (presumably defined elsewhere).
The initializeMatrix function likely fills the elements of the matrix with random 0 or 1 values as described previously.
7: // Optionally, print the initialized matrix

Another comment indicating that the following line is optional.
8: //printMatrix(matrix);

This line is a commented-out function call.
printMatrix(matrix);: This would call the printMatrix function (presumably defined elsewhere) to print the contents of the initialized matrix for visualization purposes (optional).
9: auto convMatrix = convolution(matrix);

This line performs the convolution operation:
auto: This keyword allows the compiler to automatically deduce the data type of the variable being assigned.
convMatrix = convolution(matrix);: This calls the convolution function, passing the matrix as input. The result, which is a 2D vector containing the convolution output, is assigned to the variable convMatrix.
10: cout << "Convolution Result:" << endl;

This line prints a label "Convolution Result:" to the console.
cout: This refers to the standard output stream (usually the console).
endl: This inserts a newline character after the printed message.
11: printMatrix(convMatrix);

This line calls the printMatrix function again, but this time passing the convMatrix as input.
This will print the contents of the convolution output matrix, allowing you to visualize the result of the convolution operation.
12: auto pooledMatrix = maxPooling(convMatrix);

This line performs the max pooling operation:
Similar to line 9, it uses auto and calls the maxPooling function, passing the convMatrix as input. The result, a 2D vector containing the max pooling output, is stored in the pooledMatrix variable.
**13: cout << "Max Pooling Result:" << endl;

This line prints a label "Max Pooling Result:" to the console.
14: printMatrix(pooledMatrix);

This line calls the printMatrix function with the pooledMatrix as input, printing the result of the max pooling operation for visualization.
15: return 0;

This line returns 0 from the main function, indicating successful program execution.

*/