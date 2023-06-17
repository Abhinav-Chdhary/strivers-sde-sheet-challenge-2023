
void generator(vector<int>& nums, vector<vector<int>>& res, int ind, vector<int> curr){
    if(ind>=nums.size()){
        res.push_back(curr);
        return;
    }
    curr.push_back(nums[ind]);
    generator(nums, res, ind+1, curr);
    curr.pop_back();
    generator(nums, res, ind+1, curr);
}
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> res;
    generator(v, res, 0, vector<int>());
    return res;
}