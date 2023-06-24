#include <bits/stdc++.h> 
int union_find(int u, vector<int>& parent){
	if(u==parent[u]) return u;
	return parent[u] = union_find(parent[u], parent);
}
int union_by_size(int u, int v, vector<int>& parent, vector<int>& sizes){
	int pu = union_find(u, parent);
	int pv = union_find(v, parent);
	if(pu==pv) return 0;
	if(sizes[pu]>sizes[pv]){
		parent[pv] = pu;
		sizes[u]+=sizes[v];
	}
	else{
		parent[pu] = pv;
		sizes[v]+=sizes[u];
	}
	return 1;
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	for(int i=0; i<m; i++){
		pq.push({graph[i][2], {graph[i][0], graph[i][1]}});
	}
	int res = 0;
	vector<int> parent(n+1), sizes(n+1, 0);
	for(int i=1; i<=n; i++)
		parent[i] = i;

	while(!pq.empty()){
		auto it = pq.top();
		int wt = it.first;
		int u = it.second.first;
		int v = it.second.second;
		pq.pop();
		if(union_by_size(u, v, parent, sizes))
			res += wt;
	}
	return res;
}