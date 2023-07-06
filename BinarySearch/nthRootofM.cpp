//Brute force O(sqrt(m)) or O(sqrt(m)*log(N)) if we consider t.c of
//pow function. Here N any possible root of m, 1<=N<=sqrt(m)
//works and submitted
int NthRoot(int n, int m) {
  if(n==1) return m;
  for(int i=1; i<=sqrt(m); i++){
    if((long long)pow(i, n)==m) return i;
  }
  return -1;
}
//Optimal is binary search O(logn)
int calMid(int n, int m, int mid){
  long long ans=1;
  while(n-->0){
    ans*=mid;
    if(ans>m) return 0;
  }
  if(ans==m) return 1;
  return 2;
}
int NthRoot(int n, int m) {
  if(n==1) return m;
  int l=1, r=m;
  while(l<=r){
    int mid = l+(r-l)/2;
    int flag = calMid(n, m, mid);
    if(flag==1){
      return mid;
    }
    else if(flag==0){
      r = mid-1;
    }
    else{
      l = mid+1;
    }
  }
  return -1;
}