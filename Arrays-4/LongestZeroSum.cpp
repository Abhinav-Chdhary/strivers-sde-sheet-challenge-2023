//brute force O(n^2)
int LongestSubsetWithZeroSum(vector < int > arr) {
    int ans = 0;
  for(int i=0; i<arr.size(); i++){
      int sum = 0;
      for(int j=i; j<arr.size(); j++){
          sum+=arr[j];
          if(sum==0)
            ans = max(ans, j-i+1);
      }
  }
  return ans;
}
//optimal using prefix sum
int LongestSubsetWithZeroSum(vector < int > arr) {
    unordered_map<int, int> um;
    int ans = 0, sum = 0;
  for(int i=0; i<arr.size(); i++){
      sum+=arr[i];
      if(sum==0)
        ans=i+1;
        else{
            if(um.find(sum)!=um.end()){
                ans = max(ans, i-um[sum]);
            }
            else{
                um[sum] = i;
            }
        }
  }
  return ans;
}
