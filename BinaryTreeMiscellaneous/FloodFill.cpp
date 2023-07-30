#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &img, int i, int j, int val, int newColor)
{
    if (i < 0 || i >= img.size() || j < 0 || j >= img[0].size() || img[i][j] != val || img[i][j] == newColor)
    {
        return;
    }
    img[i][j] = newColor;
    dfs(img, i - 1, j, val, newColor);
    dfs(img, i + 1, j, val, newColor);
    dfs(img, i, j - 1, val, newColor);
    dfs(img, i, j + 1, val, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    dfs(image, x, y, image[x][y], newColor);
    return image;
}

int main()
{
    // Example usage
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    int x = 1; // Row index of the starting pixel
    int y = 1; // Column index of the starting pixel
    int newColor = 2;

    cout << "Original Image:" << endl;
    for (const auto &row : image)
    {
        for (int pixel : row)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }

    image = floodFill(image, x, y, newColor);

    cout << "Image after flood fill:" << endl;
    for (const auto &row : image)
    {
        for (int pixel : row)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
