bool dfs(vector<int> adj[], int src, int ind, vector<int> &vis, vector<int> &pathVis){
        vis[ind] = 1;
        pathVis[ind] = 1;
        for(int it: adj[ind]){
            if(!vis[it]){
                if(dfs(adj, ind, it, vis, pathVis)) return true;
            }
            else if(pathVis[it]) return true;
        }
        pathVis[ind] = 0;
        return false;
    }
int detectCycleInDirectedGraph(int V, vector < pair < int, int >> & edges) {
  vector<int> adj[V+1];
  for(int i=0; i<edges.size(); i++){
        adj[edges[i].first].push_back(edges[i].second);
    }
  vector<int> vis(V+1, 0);
        vector<int> pathVis(V+1, 0);
        for(int i=1; i<=V; i++){
            if(!vis[i])
                if(dfs(adj,-1, i, vis, pathVis)) return true;
        }
        return false;
}