/*bool bfs(vector<int> adj[], int ind, vector<int> &vis){
        vis[ind] = 1;
        queue<pair<int, int>> q;
        q.push({ind, -1});
        while(!q.empty()){
            int cur = q.front().first;
            int src = q.front().second;
            q.pop();
            for(int it: adj[cur]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, cur});
                }
                else if(it!=src) return true;
            }
        }
        return false;
    }*/
    bool dfs(vector<int> adj[], int src, int ind, vector<int> &vis){
        vis[ind] = 1;
        for(int it: adj[ind]){
            if(!vis[it]){
                vis[it] = 1;
                if(dfs(adj, ind, it, vis)) return true;
            }
            else if(it!=src) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i])
                if(dfs(adj,-1, i, vis)) return true;
        }
        return false;
    }