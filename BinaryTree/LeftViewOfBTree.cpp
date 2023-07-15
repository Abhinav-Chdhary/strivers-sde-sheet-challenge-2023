vector<int> getLeftView(TreeNode<int> *root)
{
    if(!root) return {};
    queue<TreeNode<int>*> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty()){
        int sz = q.size();
        ans.push_back(q.front()->data);
        while(sz--){
            TreeNode<int>* curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return ans;
}