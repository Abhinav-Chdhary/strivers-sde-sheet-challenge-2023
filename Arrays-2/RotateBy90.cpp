#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to rotate the matrix clockwise by 90 degrees
void rotate(vector<vector<int>>& matrix) {
    // Reverse the matrix vertically
    reverse(matrix.begin(), matrix.end());

    // Transpose the matrix
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i; j < matrix.size(); j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
    // Create a sample matrix
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Rotate the matrix
    rotate(matrix);

    // Print the rotated matrix
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
