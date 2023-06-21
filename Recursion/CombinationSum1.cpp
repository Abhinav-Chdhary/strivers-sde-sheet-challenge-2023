#include <bits/stdc++.h>
void generator(vector<vector<int>>& res, vector<int> temp, vector<int>& arr, int ind, int tgt){
    if(tgt==0){
            res.push_back(temp);
    }
    if(ind>=arr.size()){
        return;
    }
    for(int i=ind; i<arr.size(); i++){
          temp.emplace_back(arr[i]);
          generator(res, temp, arr, i + 1, tgt - arr[i]);
          temp.pop_back();
    }
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> res;
    generator(res, vector<int>(), arr, 0, k);
    return res;
}