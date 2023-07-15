vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if(!root) return ans;
    map<int, vector<int>> lineToList;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        lineToList[it.second].push_back(it.first->data);
        if(it.first->left)
            q.push({it.first->left, it.second-1});
        if(it.first->right)
            q.push({it.first->right, it.second+1});
    }
    for(auto list: lineToList){
        for(auto element: list.second){
            ans.push_back(element);
        }
    }
    return ans;
}