//dfs implementation
/*
	void toposort(vector<int> adj[], vector<int>& vis, int i, int V, vector<int>& res){
        vis[i] = 1;
        for(auto it: adj[i]){
            if(!vis[it]){
                toposort(adj, vis, it, V, res);
            }
        }
        res.push_back(i);
    }*/
	//Function to return list containing vertices in Topological order. 

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ind(V, 0), res;
	    for(int i=0; i<V; i++){
	        for(int x: adj[i]){
	            ind[x]++;
	        }
	    }
	    queue<int> q;
        for(size_t i=0; i<V; i++){
            if(ind[i]==0) q.push(i);
        }
        while(!q.empty()){
	        int curr = q.front();
	        res.push_back(curr);
	        q.pop();
	        for(int x: adj[curr]){
	            ind[x]--;
	            if(ind[x]==0) q.push(x);
	        }
	    }
//	    for(int x: res) cout<<x<<" ";
//	    cout<<endl;
        return res;
	}