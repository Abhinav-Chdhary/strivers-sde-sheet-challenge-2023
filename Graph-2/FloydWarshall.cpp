int floydWarshall(int V, int m, int src, int dest, vector<vector<int>> &edges) {
        int n = V;
        vector<vector<int>> matrix(n+1, vector<int> (n+1, -1));
        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            matrix[u][v] = w;
        }
	    for(int i=0; i<=n; i++){
	        for(int j=0; j<=n; j++){
	            if(matrix[i][j]==-1) matrix[i][j] = 1e9;
                if(i==j) matrix[i][j] = 0;
	        }
	    }
	    for(int k=1; k<=n; k++){
	        for(int i=1; i<=n; i++){
	            for(int j=1; j<=n; j++){
                    if(matrix[i][k]!=1e9 && matrix[k][j]!=1e9)
	                    matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    
	    /*for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j]==1e9) matrix[i][j] = -1;
	        }
	    }*/
        return matrix[src][dest];
}