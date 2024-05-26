/*
write cpp to
1. Create a Matrix of 28 rows x 28 column
2. Initialize the Matrix with random value of 0 or 1
3. Write a function to calculate convolution on that matrix using the convolution kernel given below.
Stride Length = 1
Kernel
1 0 1
0 1 0
1 0 1
4. Write a function to calculate max pooling on that matrix returned by convolutional function in (3)
Stride Length = 1
Pooling dimension 3x3
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MATRIX_SIZE = 28;
const vector<vector<int>> KERNEL = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
const int KERNEL_SIZE = 3;
const int POOL_SIZE = 3;
// Function to initialize the matrix with random values of 0 or 1
void initializeMatrix(vector<vector<int>>& matrix) {
    srand(time(nullptr));
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            matrix[i][j] = rand() % 2;
        }
    }
}
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
// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main() {
    // Step 1: Create and initialize the matrix
    vector<vector<int>> matrix(MATRIX_SIZE, vector<int>(MATRIX_SIZE));
    initializeMatrix(matrix);
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