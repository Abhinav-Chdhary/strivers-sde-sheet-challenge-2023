class Solution {
private:
    bool isSafe(vector<string>& board, int row, int col, int n){
        int i=row, j=col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }
        i=row, j=col;
        while(i<n && j>=0){
            if(board[i][j]=='Q') return false;
            i++;
            j--;
        }
        i=row, j=col;
        while(j>=0){
            if(board[i][j]=='Q') return false;
            j--;
        }
        j=col;
        while(i>=0){
            if(board[i][j]=='Q') return false;
            i--;
        }
        return true;
    }
    void solver(vector<vector<string>>& res, vector<string> board, int col, int n){
        if(col>=n){
            res.push_back(board);
            return;
        }
        for(int i=0; i<n; i++){
            if(isSafe(board, i, col, n)){
                board[i][col] = 'Q';
                solver(res, board, col+1, n);
                board[i][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> board(n, s);
        vector<vector<string>> res;
        solver(res, board, 0, n);
        return res;
    }
};