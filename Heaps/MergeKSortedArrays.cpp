//overall time complexity of the code is O(k * n * log(k))
//the space complexity of the code is O(n + log(k))
vector<int> merger(vector<int> &a, vector<int> &b){
    vector<int> res;
    int m = a.size(), n = b.size(), i=0, j=0;
    while(i<m && j<n){
        if(a[i]<=b[j]){
            res.push_back(a[i++]);
        }
        else{
            res.push_back(b[j++]);
        }
    }
    while(i<m){
        res.push_back(a[i++]);
    }
    while(j<n){
        res.push_back(b[j++]);
    }
    return res;
}
vector<int> divideAndConquer(vector<vector<int>>&kArrays, int l, int r){
    if(l<r){
        int mid = (l+r)>>1;
        vector<int> a = divideAndConquer(kArrays, l, mid);
        vector<int> b = divideAndConquer(kArrays, mid+1, r);
        vector<int> res = merger(a, b);
        return res;
    }
    return kArrays[l];
}
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    return divideAndConquer(kArrays, 0, k-1);
}