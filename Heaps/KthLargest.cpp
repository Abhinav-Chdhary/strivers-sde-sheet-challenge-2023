int kthLargest(vector<int>& arr, int size, int K)
{
	priority_queue<int> pq;
	for(int x: arr){
		pq.push(x);
	}
	while(--K){
		pq.pop();
	}
	return pq.top();
}