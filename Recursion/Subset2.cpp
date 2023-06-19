vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp = {};
        sort(nums.begin(), nums.end());
        subsetWithDup(res, nums, temp, 0, nums.size());
        return res;
    }

    void subsetWithDup(vector<vector<int>>& res, vector<int>& nums, vector<int> t, int ind, int n){
        res.emplace_back(t);
        for(int i=ind; i<n; i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            t.push_back(nums[i]);
            subsetWithDup(res, nums, t, i+1, n);
            t.pop_back();
        }
    }