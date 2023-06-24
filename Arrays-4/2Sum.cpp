//code studio

vector<vector<int>> pairSum(vector<int> &nums, int target){
   sort(nums.begin(), nums.end());
   vector<vector<int>> res;
   for(int i=0; i<nums.size(); i++){
            int part = nums.at(i);
            for(int j=i+1; j<nums.size(); j++){
                  if(part+nums.at(i)>target) break;
                if(part+nums.at(j)==target){
                    res.push_back({nums[i], nums[j]});
                }
            }
        }
   return res;
}
//leetcode
vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            if(m.find(target-nums[i])!=m.end())
                return {m[target-nums[i]], i};
            m[nums[i]] = i;
        }
        return {0, 0};
    }