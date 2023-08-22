// Using subsets, got TLE, O(n!)+O(nlogn)
void subsetGen(set<vector<int>> &res, vector<int> nums, vector<int> ans, int cursum, int ind)
{
    if (ans.size() == 3 && cursum == 0)
    {
        res.insert(ans);
        return;
    }
    if (ind >= nums.size())
    {
        return;
    }
    for (int i = ind; i < nums.size(); i++)
    {
        ans.push_back(nums[i]);
        subsetGen(res, nums, ans, cursum + nums[i], i + 1);
        ans.pop_back();
    }
}
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    set<vector<int>> res;
    subsetGen(res, nums, vector<int>(), 0, 0);
    vector<vector<int>> resres(res.begin(), res.end());
    return resres;
}
//Using hashset got TLE again O((n^2)*logn)
vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        for(int i=0; i<nums.size(); i++){
            unordered_set<int> mine;
            for(int j=i+1; j<nums.size(); j++){
                int third = -(nums[i]+nums[j]);
                if(mine.find(third)!=mine.end()){
                    vector<int> t = {nums[i], nums[j], third};
                    res.insert(t);        
                }
                mine.insert(nums[j]);
            }
        }
        vector<vector<int>> resres(res.begin(), res.end());
        return resres;
    }
//Optimal 2-pointer approach
vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
	sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0; i<n; i++){
//            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;

            int l = i+1, h = n-1;
            int sum = 0;
            while(l<h){
                sum = nums[i]+nums[l]+nums[h];
                if(sum>K)
                    h--;
                else if(sum<K)
                    l++;
                else{
                    res.push_back({nums[i], nums[l], nums[h]});
                    int lastlocc = nums[l], lasthocc = nums[h];
                    while(l<h && nums[l] == lastlocc)
                        l++;
                    while(l<h && nums[h] == lasthocc)
                        h--;
                }
            }
        }
        return res;
}
