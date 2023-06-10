bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int vis[V];
        for(int i=0; i<V; i++) vis[i] = -1;
        queue<int> q;
        for(int i=0; i<V; i++){
            if(vis[i]!=-1) continue;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(auto x: graph[cur]){
                    if(vis[x]==-1){
                        vis[x] = !vis[cur];
                        q.push(x);
                    }
                    if(vis[x]==vis[cur]) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);
        for(int i=0; i<vis.size(); i++){
            if(vis[i]==-1){
                if(!dfs(graph, i, vis, 0)) return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph, int ind, vector<int>& vis, bool color){
        vis[ind]=color;
        for(auto i: graph[ind]){
            if(vis[i]==-1){
                if(!dfs(graph, i, vis, !color)) return false;
            }
            if(vis[i]==vis[ind]) return false;
        }
        return true;
    }