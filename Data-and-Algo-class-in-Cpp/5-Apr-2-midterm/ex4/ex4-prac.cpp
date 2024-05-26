//Write a program to check if a matrix is an identity matrix. Complete that function isIdentityMatrix bellow. Note: To check if a matrix is an identity matrix, you need to verify that it is a square matrix where all elements in the main diagonal are 1 (ones) and all other elements are 0 (zeros).

#include <iostream>
#include <vector>

using namespace std;

bool isIdentityMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (rows != cols) {
        return false;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == j) {
                if (matrix[i][j] != 1) {
                    return false;
                }
            } else {
                if (matrix[i][j] != 0) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    vector<vector<int>> matrix1 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    vector<vector<int>> matrix2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 2}
    };

    cout << "Matrix 1 is an identity matrix: " << (isIdentityMatrix(matrix1) ? "True" : "False") << endl;
    cout << "Matrix 2 is an identity matrix: " << (isIdentityMatrix(matrix2) ? "True" : "False") << endl;

    return 0;
}
