int bellmonFord(int V, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dis(V+1, 1e9);
        dis[src] = 0;
        for(int i=1; i<=V; i++){
            for(int j=0; j<edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                if(dis[u]!=1e9 && dis[u]+w<dis[v]){
                    dis[v] = dis[u]+w;
                    if(i==V){
                        return {-1};
                    }
                }
            }
        }
        return dis[dest];
}