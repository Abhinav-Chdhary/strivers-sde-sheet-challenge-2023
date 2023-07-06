//Brute force t.c O(nlogn + nlogn) s.c O(k) got TLE on codestudio
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> res;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			pq.push(a[i]+b[j]);
			if(pq.size()>k) pq.pop();
		}
	}
	while(!pq.empty()){
		res.push_back(pq.top());
		pq.pop();
	}
	sort(res.begin(), res.end(), greater<int>());
	return res;
}
//little better O(nlogn) but s.c O(n*n) but accepted
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	priority_queue<int> pq;
	vector<int> res;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			pq.push(a[i]+b[j]);
		}
	}
	while(k--){
		res.push_back(pq.top());
		pq.pop();
	}
	return res;
}