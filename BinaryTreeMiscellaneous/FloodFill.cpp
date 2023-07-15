void dfs(vector<vector<int>>& img, int i, int j, int val, int newColor){
        if(i<0 || i>=img.size() || j<0 || j>=img[0].size() || img[i][j]!=val || img[i][j]==newColor){
            return;
        }
        img[i][j] = newColor;
        dfs(img, i-1, j, val, newColor);
        dfs(img, i+1, j, val, newColor);
        dfs(img, i, j-1, val, newColor);
        dfs(img, i, j+1, val, newColor);
    }
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
     dfs(image, x, y, image[x][y], newColor);
        return image;
}