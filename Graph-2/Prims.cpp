int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //{weight, curr}
        pq.push({0, 0});
        vector<int> vis(V, 0);
        int sum=0, i=0;
        while(!pq.empty()){
            auto it = pq.top();
            int wt = it.first;
            int cur = it.second;
            pq.pop();
            if(vis[cur]) continue;
            sum += wt;
            vis[cur] = 1;
            for(auto it: adj[cur]){
                if(!vis[it[0]]){
                    pq.push({it[1], it[0]});
                }
            }
        }
        return sum;
    }