//Optimal solution O(n^2*logn)
string fourSum(vector<int> nums, int target, int n) {
    sort(nums.begin(), nums.end());
    //vector<vector<int>> res;
    for(int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j>0 && nums[j]==nums[j-1]) continue;
            int l = j+1, h = n-1;
            int sum = 0;
            while(l<h){
                sum = nums[i]+nums[j]+nums[l]+nums[h];
                if(sum>target)
                    h--;
                else if(sum<target)
                    l++;
                else{
                    return "Yes";
                }
            }
        }
    }
    return "No";
}
//leetcode version
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        for(int i=0; i<n; i++){
            //if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                //if(j>0 && nums[j]==nums[j-1]) continue;
                int l = j+1, h = n-1;
                long long sum = 0;
                while(l<h){
                    sum = (long long)nums[i]+nums[j]+nums[l]+nums[h];
                    if(sum>target)
                        h--;
                    else if(sum<target)
                        l++;
                    else{
                        res.insert({nums[i], nums[j], nums[l], nums[h]});
                        int lastlocc = nums[l], lasthocc = nums[h];
                        while (l < h && nums[l] == lastlocc)
                            l++;
                        while (l < h && nums[h] == lasthocc)
                            h--;
                    }
                }
            }
        }
        return vector<vector<int>> (res.begin(), res.end());
    }