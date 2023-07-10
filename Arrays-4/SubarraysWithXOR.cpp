//Brute force O(n^2)
int subarraysXor(vector<int> &arr, int x)
{
    int cnt = 0, n = arr.size();
    for(int i=0; i<n; i++){
        int mask = 0;
        for(int j=i; j<n; j++){
            mask = (mask^arr[j]);
            if(mask==x) cnt++;
        }
    }
    return cnt;
}
//Optimal O(n)
int subarraysXor(vector<int> &arr, int k)
{
    int cnt = 0, n = arr.size();
    unordered_map<int, int> um;
    int xr = 0;
    um[0]++;
    for(int i=0; i<n; i++){
        xr ^= arr[i];

        if(um.find(xr^k)!=um.end()){
            cnt += um[xr^k];
        }
        um[xr]++;
    }
    return cnt;
}
