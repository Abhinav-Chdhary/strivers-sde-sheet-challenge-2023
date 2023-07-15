//Brute Force
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	vector<int> ans;
	for(int i=0; i<queries.size(); i++){
		int mxor = 0, flag=0;
		for(int j=0; j<arr.size(); j++){
			if(queries[i][1]>=arr[j]){
				flag=1;
				mxor = max(mxor, queries[i][0]^arr[j]);
			}
		}
		if(!flag) ans.push_back(-1);
		else ans.push_back(mxor);
	}
	return ans;
}