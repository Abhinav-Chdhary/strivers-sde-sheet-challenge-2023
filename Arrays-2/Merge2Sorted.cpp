//with extra space O(m) and T.C = O(m+n)

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	vector<int> copy = arr1;
	int i=0, j=0, k=0;
	while(i<m && j<n){
		if(copy[i]<=arr2[j]){
			arr1[k] = copy[i];
			i++;
		}
		else{
			arr1[k] = arr2[j];
			j++;
		}
		k++;
	}
	while(i<m){
		arr1[k++] = copy[i++];
	}
	while(j<n){
		arr1[k++] = arr2[j++];
	}
	return arr1;
}
//without extra space t.c: O(nlogn)
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	arr1.resize(m);
	int i=m-1, j=0, k=0;
	while(i>=0 && j<n){
		if(arr1[i]>arr2[j]){
			swap(arr1[i], arr2[j]);
		}
		else{
			break;
		}
		i--; j++;
	}
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	arr1.resize(m+n, 0);
	for(int i=m; i<m+n; i++){
		arr1[i] = arr2[k++];
	}
	return arr1;
}