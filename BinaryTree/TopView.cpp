vector<int> getTopView(TreeNode<int> *root) {
    if(!root) return {};
    //to store the first node of every vertical line
    map<int, int> lineToNode;
    //to traverse the queue
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    //to store the ans
    vector<int> ans;

    while(!q.empty()){
        TreeNode<int>* curr = q.front().first;
        int line = q.front().second;
        if(lineToNode.find(line)==lineToNode.end()){
            lineToNode[line] = curr->val;
        }
        q.pop();
        if(curr->left)
            q.push({curr->left, line-1});
        if(curr->right)
            q.push({curr->right, line+1});
    }
    for(auto item: lineToNode){
        ans.push_back(item.second);
    }
    return ans;

}