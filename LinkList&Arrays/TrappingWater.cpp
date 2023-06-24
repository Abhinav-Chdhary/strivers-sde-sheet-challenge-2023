//code studio and leetcode
long getTrappedWater(long *arr, int n){
    if(n<3) return 0;
    long l = 0, r =n-1;
    long leftmax =0, rightmax=0;
    long totalwater=0;

    while(l<=r){
      if (arr[l] <= arr[r]) {
        if (arr[l] >= leftmax)
          leftmax = arr[l];
        else
          totalwater += leftmax - arr[l];
        l++;
      } else {
        if (arr[r] >= rightmax)
          rightmax = arr[r];
        else
          totalwater += rightmax - arr[r];
        r--;
      }
    }
    return totalwater;
}
//leetcode: "Container with most water"
int maxArea(vector<int>& height) {
        int maxWater = 0, n = height.size();
        int l = 0, r = n-1;
        while(l<r){
            int currWater = (r-l)*min(height[l], height[r]);
            maxWater = max(maxWater, currWater);
            if(height[l]<height[r])
                l++;
            else if(height[l]>height[r])
                r--;
            else{l++; r--;}
        }
        return maxWater;
    }