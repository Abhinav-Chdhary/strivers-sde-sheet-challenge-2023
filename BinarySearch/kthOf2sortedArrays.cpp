//Brute force t.c O(n+m)
//we might traverse both the arrays in the worst case
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int i=0, j=0, ans=-1;
    while(i<m && j<n){
        if(row1[i]<=row2[j]){
            ans = row1[i++];
            k--;
        }
        else{
            ans = row2[j++];
            k--;
        }
        if(k==0) return ans;
    }
    while(i<m){
        ans = row1[i++];
            k--;
            if(k==0) return ans;
    }
    while(j<n){
        ans = row2[j++];
        k--;
        if(k==0) return ans;
    }
    return -1;
}
//optimal using binary search O(log(n+m))