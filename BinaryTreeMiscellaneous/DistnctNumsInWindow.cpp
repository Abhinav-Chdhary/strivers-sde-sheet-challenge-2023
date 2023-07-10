//Brute force nearly O(n^2)
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    int n = arr.size();
    vector<int> ans;
    for(int i=0; i<=n-k; i++){
        unordered_set<int> s;
        for(int j=i; j<i+k; j++){
            s.insert(arr[j]);
        }
        ans.push_back(s.size());
    }
    return ans;
}
//Better O(k+n) and s.c O(n)
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    int n = arr.size();
    unordered_map<int, int> freq;
    vector<int> ans; int count=0;
    for (int i = 0; i < k; i++) {
        if (freq[arr[i]] == 0) {
            count++;
        }
        freq[arr[i]]++;
    }
    ans.push_back(count);
    for(int i=k; i<n; i++){
        freq[arr[i-k]]--;
        if(freq[arr[i-k]]==0)
            count--;
        if(freq[arr[i]]==0)
            count++;
        freq[arr[i]]++;
        ans.push_back(count);
    }
    return ans;
}
