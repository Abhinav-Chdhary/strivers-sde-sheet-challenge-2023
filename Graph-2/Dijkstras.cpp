vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
            vector<int> dis(V, INT_MAX);
            vector<int> parent(V);
            for(int i=0; i<V; i++) parent[i] = i;
            set<pair<int, int>> q;
            //pair<distance, vertice>
            dis[S] = 0;
            q.insert({0, S});
            while(!q.empty()){
                auto it = *(q.begin());
                int curn = it.second;
                int curd = it.first;
                q.erase(it);
                for(auto x: adj[curn]){
                    if(curd+x[1]<dis[x[0]]){
                        parent[x[0]] = curn;
                        dis[x[0]] = curd+x[1];
                        q.insert({dis[x[0]], x[0]});
                    }
                }
            }
        return dis;
    }