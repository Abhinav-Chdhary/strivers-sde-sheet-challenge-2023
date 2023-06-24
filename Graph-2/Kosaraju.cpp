#include <bits/stdc++.h>
void dfs(vector<int>& vis, vector<int> adj[], int i, stack<int>& stk){
	    vis[i] = 1;
	    for(int ind: adj[i]){
	        if(!vis[ind])
	            dfs(vis, adj, ind, stk);
	    }
	    stk.push(i);
	}
	void dfs(vector<int>& vis, vector<int> adj[], int i, vector<int>& curr){
	    vis[i] = 1;
	    for(int ind: adj[i]){
	        if(!vis[ind])
	            dfs(vis, adj, ind, curr);
	    }
        curr.push_back(i);
	}
vector<vector<int>> stronglyConnectedComponents(int V, vector<vector<int>> &edges)
{
        vector<int> vis(V, 0);
        vector<int> adj[V];
        for(auto i: edges) 
            adj[i[0]].push_back(i[1]);

        stack<int> stk;
        for(int i=0; i<V; i++){
            if(!vis[i])
                dfs(vis, adj, i, stk);
        }
        int count=0;
        vector<int> newAdj[V+1];
        for(int i=0; i<V; i++){
            vis[i] = 0;
            for(int it: adj[i]){
                newAdj[it].push_back(i);
            }
        }
        vector<vector<int>> res;
        while(!stk.empty()){
            int top = stk.top();
            stk.pop();
            if(!vis[top]){
                vector<int> curr;
                dfs(vis, newAdj, top, curr);
                res.push_back(curr);
            }
        }
        return res;
}