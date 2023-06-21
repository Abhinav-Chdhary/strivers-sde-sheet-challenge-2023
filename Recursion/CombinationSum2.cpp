#include <bits/stdc++.h>
void combinationSum(set<vector<int>>& res, int ind, int n, vector<int>& cand, int tgt, vector<int> v){
        if(tgt==0){
                res.insert(v);
				return;
        }
		if(ind>=n){
			  return;
        }
        for(int i=ind; i<n; i++){
			if(i>ind && cand[i]==cand[i-1]) continue;
			if(cand[i]<=tgt){
				v.push_back(cand[i]);
				combinationSum(res, i+1, n, cand, tgt-cand[i], v);
				v.pop_back();
			}
		}
    }
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	sort(arr.begin(), arr.end());
	set<vector<int>> res;
	combinationSum(res, 0, arr.size(), arr, target, vector<int>());
	vector<vector<int>> reses(res.begin(), res.end());
	return reses;
}