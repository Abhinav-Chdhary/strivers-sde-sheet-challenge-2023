vector<int> bottomView(BinaryTreeNode<int> * root){

    if(!root) return {};
    //to store the first node of every vertical line
    map<int, int> lineToNode;
    //to traverse the queue
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    //to store the ans
    vector<int> ans;

    while(!q.empty()){
        BinaryTreeNode<int> * curr = q.front().first;
        int line = q.front().second;
        lineToNode[line] = curr->data;
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