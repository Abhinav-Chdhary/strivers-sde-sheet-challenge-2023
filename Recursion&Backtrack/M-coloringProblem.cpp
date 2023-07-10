bool checkColor(int node, vector<int> adj[], vector<int> &colors, int thisColor){
    for(int neighbour: adj[node]){
        if(colors[neighbour]==thisColor)
            return false;
    }
    return true;
}
bool colorGraph(int node, vector<int> adj[], vector<int> &color, int M, int V){
    if(node==V){
        return true;
    }
    for(int i=1; i<=M; i++){
        if(checkColor(node, adj, color, i)){
            color[node] = i;
            if(colorGraph(node+1, adj, color, M, V)) return true;
            color[node] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int M) {
    int V = mat.size();
    vector<int> adjList[V];
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(mat[i][j]==1){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    vector<int> color(V, 0);
    if(colorGraph(0, adjList, color, M, V)) return "YES";
    return "NO";
}