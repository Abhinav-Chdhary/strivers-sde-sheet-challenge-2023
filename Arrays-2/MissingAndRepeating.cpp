//Extreme Brute Force O(n^2)
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	pair<int, int> ans = {-1, -1};
	for(int i=0; i<n; i++){
		int cnt=0;
		for(int j=0; j<n; j++){
			if((i+1)==arr[j]) cnt++;
		}	
		if(cnt==2) ans.second=i+1;
		if(cnt==0) ans.first = i+1;
	}
	return ans;
}
//Optimal with extra space t.c=>O(n) s.c=> O(n)
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	vector<int> freq(n, 0);
	pair<int, int> ans = {-1, -1};
	for(int i=0; i<n; i++){
		freq[arr[i]-1]++;
	}
	for(int i=0; i<n; i++){
		if(freq[i]==2)
			ans.second = i+1;
		if(freq[i]==0)
			ans.first = i+1;
	}
	return ans;
}
//Optimal using maths
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	//missing, repeating
	pair<int, int> ans = {-1, -1};
	//sum till n natural numbers
	long long Sn = (n*(n+1))/2;
	//sum till square of n natural numbers
	long long Sn2 = (n*(n+1)*(2*n+1))/6;
	//For similar sums of given array
	long long S=0, S2=0;

	for(int i=0; i<n; i++){
		S += arr[i];
		S2 += (long long)arr[i]*(long long)arr[i];
	}
	//ans.repeating - ans.missing
	int val1 = S-Sn;
	//(ans.repeating - ans.missing)^2
	int val2 = S2 - Sn2;
	//ans.repeating + ans.missing
	int val3 = val2/val1;
	//ans.repeating
	ans.second = (val3+val1)/2;
	//ans.missing
	ans.first = ans.second-val1;

	return ans;
}

