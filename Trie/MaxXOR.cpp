//Brute force O(n^2)
int maximumXor(vector<int> A)
{
    if(A.size()==1) return 0;
    //sort(A.begin(), A.end());
    int i=0, n=A.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ans = max(A[i]^A[j], ans);
        }
    }
    return ans;
}
//Optimal using trie