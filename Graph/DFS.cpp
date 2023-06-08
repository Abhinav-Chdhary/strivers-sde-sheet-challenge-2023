void dfs(int ind, vector<int> &vis, vector<int> &temp, vector<int> adjList[]){
    vis[ind] = 1;
    temp.push_back(ind);
    for(auto i: adjList[ind]){
        if(!vis[i]){
            dfs(i, vis, temp, adjList);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //create adjacency list
    vector<int> adjList[V];
    for(int i=0; i<E; i++){
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    vector<vector<int>> res;
    vector<int> vis(V, 0);
    for(int i=0; i<V; i++){
      if (!vis[i]) {
        vector<int> temp;
        dfs(i, vis, temp, adjList);
        res.push_back(temp);
      }
    }
    return res;
}