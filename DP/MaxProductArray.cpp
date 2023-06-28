/*Brute will be to generate all subarrays and calculate sum

Optimal: Observation
if all positives, then we multiply whole array
if even -ve, and other +ve then we can still multiply whole
if odd -ve, we'll break the array at the lowest -ve and return
prefix or suffix sum. Hence, we do that.*/
int maxProduct(vector<int>& nums) {
        int pro = 1, PrefixMax=INT_MIN, SuffixMax=INT_MIN;
        bool zeroFlag=0;
        for(int x: nums){
            if(x==0){
                pro = 1;
                zeroFlag = 1;
                continue;
            }
            pro*=x;
            PrefixMax = max(PrefixMax, pro);
        }
        pro = 1;
        for(int i=nums.size()-1; i>=0; i--){
            int x = nums[i];
            if(x==0){
                pro = 1;
                zeroFlag = 1;
                continue;
            }
            pro*=x;
            SuffixMax = max(SuffixMax, pro);
        }
        if(zeroFlag) return max(0, max(PrefixMax, SuffixMax));
        return max(PrefixMax, SuffixMax);
    }
