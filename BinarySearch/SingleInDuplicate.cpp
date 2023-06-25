//Brute force
int singleNonDuplicate(vector<int>& arr)
{
	int mask = arr[0];
	for(int i=1; i<arr.size(); i++){
		mask = (mask^arr[i]);
	}
	return mask;
}
//using binary search
int singleNonDuplicate(vector<int>& arr)
{
	int l = 0, r = arr.size()-2;
	while(l<=r){
		int mid = l+(r-l)/2;
		if(arr[mid]==arr[mid^1])
			l = mid+1;
		else
			r = mid-1;
	}
	return arr[l];
}