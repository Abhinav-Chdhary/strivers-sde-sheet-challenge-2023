int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    
        queue<pair<int, int>> myQueue;
        int cnt=0, maxt = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    myQueue.push({i, j});
                }
                if(grid[i][j]==1) cnt++;
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!myQueue.empty()){
            int sz = myQueue.size();
            while(sz--){
                int r = myQueue.front().first;
                int c = myQueue.front().second;
                myQueue.pop();
                for(int it=0; it<4; it++){
                    int nrow = r+drow[it];
                    int ncol = c+dcol[it];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1){
                        grid[nrow][ncol] = 2;
                        myQueue.push({nrow, ncol});
                        cnt--;
                    }
                }
            }
            maxt++;
        }
        if(cnt!=0) return -1;
        if(maxt == -1) return 0;
        return maxt;
}