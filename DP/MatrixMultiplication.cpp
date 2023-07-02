//Recurrence relation
//-----------------------------------------
int solver(int i, int j, vector<int> &arr){
    if(i==j) return 0;
    int minc = INT_MAX;
    for(int k=i; k<j; k++){
        int cost = arr[i-1]*arr[k]*arr[j]+solver(i, k, arr)+solver(k+1, j, arr);
        minc = min(cost, minc);
    }
    return minc;
}
int matrixMultiplication(vector<int> &arr, int N) { 
    return solver(1, N-1, arr); 
}
//Memoization
//-----------------------------------------
int solver(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int minc = INT_MAX;
    for(int k=i; k<j; k++){
        int cost = arr[i-1]*arr[k]*arr[j]+solver(i, k, arr, dp)+solver(k+1, j, arr, dp);
        minc = min(cost, minc);
    }
    return dp[i][j]=minc;
}
int matrixMultiplication(vector<int> &arr, int N) { 
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solver(1, N-1, arr, dp); 
}