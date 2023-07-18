TreeNode<int>* prevs = NULL;
void flattenTree(TreeNode<int>* root){
    if(!root) return;
    flattenTree(root->right);
    flattenTree(root->left);
    root->right = prevs;
    root->left = NULL;
    prevs = root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    flattenTree(root);
    prevs = NULL;
    return root;
}
//iterative
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if(!root) return root;
    stack<TreeNode<int>*> stk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode<int>* cur = stk.top();
        stk.pop();
        if(cur->right) stk.push(cur->right);
        if(cur->left) stk.push(cur->left);
        if(!stk.empty()) cur->right = stk.top();
        cur->left = NULL;
    }
    return root;
}