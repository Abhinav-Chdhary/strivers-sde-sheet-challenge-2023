#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int m = mat.size();    // Number of rows in the matrix
    int n = mat[0].size(); // Number of columns in the matrix
    int l = 0;             // Initialize left pointer to the first element in the flattened matrix
    int r = m * n - 1;     // Initialize right pointer to the last element in the flattened matrix

    while (l <= r)
    {
        int mid = l + (r - l) / 2;       // Calculate the middle index in the flattened matrix
        int val = mat[mid / n][mid % n]; // Extract the value from the matrix at the middle index

        if (val == target)
        {
            return true; // Target found in the matrix
        }
        else if (val > target)
        {
            r = mid - 1; // Update the right pointer to search the left half of the flattened matrix
        }
        else
        {
            l = mid + 1; // Update the left pointer to search the right half of the flattened matrix
        }
    }
    return false; // Target not found in the matrix
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    int target = 3;

    bool found = searchMatrix(matrix, target);
    if (found)
    {
        cout << "Target " << target << " found in the matrix." << endl;
    }
    else
    {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}
