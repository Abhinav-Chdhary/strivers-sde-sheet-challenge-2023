int traverse(BinaryTreeNode<int>* root){
    if(!root) return 0;
    int left = traverse(root->left);
    if(left==-1) return -1;
    int right = traverse(root->right);
    if(right==-1 || abs(left-right)>1) return -1;
    return 1+max(left, right);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    return traverse(root)!=-1;
}
 bool isBalanced(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            int left = height(cur->left);
            int right = height(cur->right);
            if(abs(left-right)>1)
                return false;
        }
        return true;
    }
    int height(TreeNode* root){
        if(!root) return true;
        int left = height(root->left);
        int right = height(root->right);
        return 1+max(left, right);
    }