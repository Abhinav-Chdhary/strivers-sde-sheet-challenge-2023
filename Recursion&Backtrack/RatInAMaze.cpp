//T.C => O(4^(n+m))
void findPaths(vector<vector<int>> &res, vector<vector<int>> path, int i, int j, vector<vector<int>> &maze, int n){
  if(i==n-1 && j==n-1){
    path[i][j] = 1;
    vector<int> cur;
    for(int row=0; row<n; row++){
      for(int col=0; col<n; col++){
        cur.push_back(path[row][col]);
      }
    }
    res.push_back(cur);
    return;
  }
  if(i<0 || j<0 || i>=n || j>=n || maze[i][j]==0) return;
  int dir[] = {-1, 0, 1, 0, -1};

  for(int k=0; k<4; k++){
    int x = i+dir[k];
    int y = j+dir[k+1];
    if(x>=0 && y>=0 && x<n && y<n && path[x][y]!=1){
      path[i][j] = 1;
      findPaths(res, path, x, y, maze, n);
      path[i][j] = 0;
    }
  }
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> result;
  vector<vector<int>> path(n, vector<int> (n, 0));
  path[0][0] = 1;
  findPaths(result, path, 0, 0, maze, n);
  return result;
}
//We can do this with BFS also I think