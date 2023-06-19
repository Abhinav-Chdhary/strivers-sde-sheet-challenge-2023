void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i=0; i<matrix.size(); i++){
            for(int j=i; j<matrix.size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }