int removeDuplicates(vector<int>& nums) {
        int count=0;
        for(int j=1; j<nums.size(); j++){
            if(nums[j-1]!=nums[j]){
                nums[++count] = nums[j];
            }
        }
        return count+1;
    }