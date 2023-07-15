int getMaxWidth(TreeNode<int> *root)
{
    int ans = 0;
    if(!root) return ans;
    queue<TreeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        ans = max(ans, sz);
        while(sz--){
            auto it = q.front();
            q.pop();
            if(it->left)
                q.push(it->left);
            if(it->right)
                q.push(it->right);
        }
    }
    return ans;
}