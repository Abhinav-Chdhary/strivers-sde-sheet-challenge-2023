int search(int* nums, int n, int target) {
    int lo = 0, hi = n-1;
    while (lo <= hi) {
        int mid = lo+(hi-lo)/2;
        if(nums[mid]==target) return mid;
        if(nums[lo]<=nums[mid]){
            //left sorted
            if(target>=nums[lo] && target<nums[mid]){
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        else if(nums[lo]>=nums[mid]){
            //right sorted
            if(target>nums[mid] && target<=nums[hi])
                lo = mid+1;
            else
                hi = mid-1;
        }
        
    }
    return -1;
}