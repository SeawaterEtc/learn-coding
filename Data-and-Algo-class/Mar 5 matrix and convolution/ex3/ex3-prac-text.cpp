#include <iostream>
#include <vector>

// Convolution function
std::vector<std::vector<int>> convolution(const std::vector<std::vector<int>>& matrix) {
    // Define the convolution kernel
    std::vector<std::vector<int>> kernel = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    int rows = matrix.size();
    int cols = matrix[0].size();
    int kernelSize = kernel.size();
    int halfKernel = kernelSize / 2;

    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

    // Apply convolution
    for (int i = halfKernel; i < rows - halfKernel; ++i) {
        for (int j = halfKernel; j < cols - halfKernel; ++j) {
            int sum = 0;
            for (int ki = 0; ki < kernelSize; ++ki) {
                for (int kj = 0; kj < kernelSize; ++kj) {
                    sum += matrix[i - halfKernel + ki][j - halfKernel + kj] * kernel[ki][kj];
                }
            }
            result[i][j] = sum;
        }
    }

    return result;
}

// Max pooling function
std::vector<std::vector<int>> maxPooling(const std::vector<std::vector<int>>& matrix, int poolSize) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int poolStride = 1; // Stride length for max pooling

    std::vector<std::vector<int>> result(rows / poolSize, std::vector<int>(cols / poolSize, 0));

    // Apply max pooling
    for (int i = 0; i < rows; i += poolStride) {
        for (int j = 0; j < cols; j += poolStride) {
            int maxVal = matrix[i][j];
            for (int pi = 0; pi < poolSize; ++pi) {
                for (int pj = 0; pj < poolSize; ++pj) {
                    maxVal = std::max(maxVal, matrix[i + pi][j + pj]);
                }
            }
            result[i / poolSize][j / poolSize] = maxVal;
        }
    }

    return result;
}

int main() {
    // Example usage
    std::vector<std::vector<int>> inputMatrix = {
        {2, 3, 1, 4},
        {0, 1, 2, 3},
        {3, 2, 1, 0},
        {1, 4, 3, 2}
    };

    std::vector<std::vector<int>> convolvedMatrix = convolution(inputMatrix);
    std::vector<std::vector<int>> pooledMatrix = maxPooling(convolvedMatrix, 3);

    // Print the convolved matrix
    std::cout << "Convolved Matrix:" << std::endl;
    for (const auto& row : convolvedMatrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Print the pooled matrix
    std::cout << "\nMax Pooled Matrix:" << std::endl;
    for (const auto& row : pooledMatrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
