#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long res = LONG_MIN, sum = 0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        res = max(res, sum);
        if(sum<0) sum=0;
    }
    return res>0?res:0;
}