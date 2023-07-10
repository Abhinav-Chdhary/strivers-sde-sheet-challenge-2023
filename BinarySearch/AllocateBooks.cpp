//Brute Force O(n^2)
bool checkAllocate(long long i, vector<int> &time, int m, int n){
	int ind=0, day=1;
	while(ind<m && day<=n){
		long long sum = time[ind++];
		while(ind<m && sum+time[ind]<=i){
			sum+=time[ind];
			ind++;
		}
		day++;
	}
	return !(ind<m);
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long mmin=time[0], mmax=0;
	for(int i=0; i<m; i++){
		mmin = max((long long)time[i], mmin);
		mmax += time[i];
	}
	for(int i=mmin; i<mmax; i++){
		if(checkAllocate(i, time, m, n))
			return i;
	}
	return mmax;
}
//Binary search O(nlogn)
bool checkAllocate(long long i, vector<int> &time, int m, int n){
	int ind=0, day=1;
	while(ind<m && day<=n){
		long long sum = time[ind++];
		while(ind<m && sum+time[ind]<=i){
			sum+=time[ind];
			ind++;
		}
		day++;
	}
	return !(ind<m);
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long mmin=time[0], mmax=0;
	for(int i=0; i<m; i++){
		mmin = max((long long)time[i], mmin);
		mmax += time[i];
	}
	while(mmin<=mmax){
		long long mid = (mmin+mmax)>>1;
		if(checkAllocate(mid, time, m, n)){
			mmax = mid-1;
		}
		else{
			mmin = mid+1;
		}
	}
	return mmin;
}