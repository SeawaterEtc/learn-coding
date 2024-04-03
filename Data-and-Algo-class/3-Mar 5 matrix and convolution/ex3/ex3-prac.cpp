#include <iostream>
#include <vector>

using namespace std;

// Function to perform convolution with stride 1 and padding for boundary handling
vector<vector<int>> convolution(const vector<vector<int>>& image,
                                 const vector<vector<int>>& kernel) {
    int image_rows = image.size();
    int image_cols = image[0].size();
    int kernel_rows = kernel.size();
    int kernel_cols = kernel[0].size();

    // Calculate output dimensions with padding
    int output_rows = image_rows - kernel_rows + 1;
    int output_cols = image_cols - kernel_cols + 1;
    vector<vector<int>> output(output_rows, vector<int>(output_cols, 0));

    // Handle boundary conditions using zero padding
    int pad_row = (kernel_rows - 1) / 2;
    int pad_col = (kernel_cols - 1) / 2;
    vector<vector<int>> padded_image(image_rows + 2 * pad_row, vector<int>(image_cols + 2 * pad_col, 0));

    // Copy image data with padding
    for (int i = 0; i < image_rows; i++) {
        for (int j = 0; j < image_cols; j++) {
            padded_image[i + pad_row][j + pad_col] = image[i][j];
        }
    }

    // Perform convolution with stride 1
    for (int i = 0; i < output_rows; i++) {
        for (int j = 0; j < output_cols; j++) {
            for (int k = 0; k < kernel_rows; k++) {
                for (int l = 0; l < kernel_cols; l++) {
                    output[i][j] += padded_image[i + k][j + l] * kernel[k][l];
                }
            }
        }
    }

    return output;
}

// Function to perform max pooling with stride 1 and 3x3 pooling dimension
vector<vector<int>> max_pooling(const vector<vector<int>>& feature_map) {
    int rows = feature_map.size();
    int cols = feature_map[0].size();

    // Validate pooling dimension (must be odd and less than or equal to feature map dimensions)
    int pool_size = 3;  // Replace with desired pooling size
    if (pool_size % 2 != 1 || pool_size > rows || pool_size > cols) {
        cerr << "Invalid pooling dimension. Pooling size must be odd and less than or equal to feature map dimensions." << endl;
        return feature_map;  // Return original feature map as an error indicator
    }

    int output_rows = (rows - pool_size + 1) / 1;  // Stride 1 for max pooling
    int output_cols = (cols - pool_size + 1) / 1;
    vector<vector<int>> output(output_rows, vector<int>(output_cols, 0));

    for (int i = 0; i < output_rows; i++) {
        for (int j = 0; j < output_cols; j++) {
            int max_value = INT_MIN;  // Initialize with minimum integer value
            for (int k = 0; k < pool_size; k++) {
                for (int l = 0; l < pool_size; l++) {
                    max_value = max(max_value, feature_map[i * 1 + k][j * 1 + l]);  // Stride 1
                }
            }
            output[i][j] = max_value;
        }
    }

    return output;
}

int main() {
    // Sample image and kernel (modify as needed)
    vector<vector<int>> image = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> kernel = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};

    // Perform convolution
    vector<vector<int>> feature_map = convolution(image, kernel);

    // Perform max pooling
    vector<vector<int>> pooled_output = max_pooling(feature_map);

    // Print the convolution output
    cout << "Convolution Output:" << endl;
    for (const auto& row : feature_map) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    // Print the max pooling output
    cout << endl << "Max Pooling Output:" << endl;
    for (const auto& row : pooled_output) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
