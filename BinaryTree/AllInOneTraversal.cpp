vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans(3);
    if(!root) return ans;
    stack<pair<BinaryTreeNode<int> *, int>> stk;
    stk.push({root, 0});
    while(!stk.empty()){
       auto it = stk.top();
        stk.pop();
        if(it.second==0){
            ans[1].push_back(it.first->data);
            it.second++;
            stk.push(it);
            if(it.first->left){
                stk.push({it.first->left, 0});
            }
        }
        else if(it.second==1){
            ans[0].push_back(it.first->data);
            it.second++;
            stk.push(it);
            if(it.first->right){
                stk.push({it.first->right, 0});
            }
        }
        else if(it.second==2){
            ans[2].push_back(it.first->data);
        }
    }
    return ans;
}