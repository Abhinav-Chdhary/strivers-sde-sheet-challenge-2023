void generator(vector<int>& nums, vector<int> &res, int ind, int curr){
    if(ind>=nums.size()){
        res.push_back(curr);
        return;
    }
    generator(nums, res, ind+1, curr+nums[ind]);
    generator(nums, res, ind+1, curr);
}
vector<int> subsetSum(vector<int> &nums)
{
    vector<int> res;
    generator(nums, res, 0, 0);
    sort(res.begin(), res.end());
    return res;
}