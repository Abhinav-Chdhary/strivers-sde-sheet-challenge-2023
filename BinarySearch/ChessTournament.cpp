//Greedy O(nlogn) Wrong answer

int chessTournament(vector<int> posi , int n ,  int c){
	sort(posi.begin(), posi.end());
	int pans = abs(posi[0]-posi[n-1]);
	return (pans/(c-1));
}
//Brute Force O(nlogn+n*m)
//where m is maximmum gap and n is size of array
bool isValid(vector<int> &posi, int gap, int n, int c){
	int lastPut = posi[0];
	c--;
	for(int i=1; i<n; i++){
		if(posi[i]>=lastPut+gap){
			c--;
			lastPut = posi[i];
		}
	}
	if(c>0) return false;
	return true;
}
int chessTournament(vector<int> posi , int n ,  int c){
	sort(posi.begin(), posi.end());
	int limit = posi[n-1]-posi[0];
	int ans = -1;
	for(int i=1; i<=limit; i++){
		if(isValid(posi, i, n, c)){
			ans = i;
		}
	}
	return ans;
}
//Optimal using Binary Search O(nlogn+n*log(m))
bool isValid(vector<int> &posi, int gap, int n, int c){
	int lastPut = posi[0];
	c--;
	for(int i=1; i<n; i++){
		if(posi[i]>=lastPut+gap){
			c--;
			lastPut = posi[i];
		}
	}
	if(c>0) return false;
	return true;
}
int chessTournament(vector<int> posi , int n ,  int c){
	sort(posi.begin(), posi.end());
	int l=1, r = posi[n-1]-posi[0];
	int ans = 1;
	while(l<=r){
		int mid = (l+r)/2;
		if(isValid(posi, mid, n, c)){
			ans = max(ans, mid);
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	return ans;
}