//Recurrence
bool isPalin(string s){
    int n = s.size();
    if(n==1) return true;
    for(int i=0; i<n/2; i++){
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;
}
int frontPart(string &str, int ind){
    if(ind>=str.size()){
        return 0;
    }
    string tmp = "";
    int minCost = INT_MAX;
    for(int i=ind; i<str.size(); i++){
        tmp += str[i];
        int cost = INT_MAX;
        if(isPalin(tmp)){
            cost = 1+ frontPart(str, i+1);
        }
        minCost = min(cost, minCost);
    }
    return minCost;
}
int palindromePartitioning(string str) {
    return frontPart(str, 0)-1;
}
//Memoization using 1D array
//1 D array is enough because we parition from front
bool isPalin(string s){
    int n = s.size();
    if(n==1) return true;
    for(int i=0; i<n/2; i++){
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;
}
int frontPart(string &str, int ind, vector<int> &dp){
    if(ind>=str.size()){
        return 0;
    }
    if(dp[ind]!=-1) return dp[ind];
    string tmp = "";
    int minCost = INT_MAX;
    for(int i=ind; i<str.size(); i++){
        tmp += str[i];
        int cost = INT_MAX;
        if(isPalin(tmp)){
            cost = 1+ frontPart(str, i+1, dp);
        }
        minCost = min(cost, minCost);
    }
    return dp[ind]=minCost;
}
int palindromePartitioning(string str) {
    vector<int> dp(str.size(), -1);
    return frontPart(str, 0, dp)-1;
}
//Tablulation
bool isPalin(int i, int j, string s){
    int n = s.size();
    if(n==1) return true;
    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++; j--;
    }
    return true;
}

int palindromePartitioning(string str) {
    vector<int> dp(str.size()+1, 0);
    for(int ind=str.size()-1; ind>=0; ind--){
        int minCost = INT_MAX;
        for(int i=ind; i<str.size(); i++){
            int cost = INT_MAX;
            if(isPalin(ind, i, str)){
                cost = 1+ dp[i+1];
            }
            minCost = min(cost, minCost);
        }
        dp[ind]=minCost;
    }
    return dp[0]-1;
}

