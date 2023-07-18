void inverter(TreeNode<int>* root, TreeNode<int>* prev, TreeNode<int>* leaf, bool &q, TreeNode<int>* &ans){
    if(!root) return;
    if(root->data==leaf->data){
        root->left = prev;
        q = 1;
        ans = root;
        return;
    }
    inverter(root->left, root, leaf, q, ans);
    if(q){
        root->left = prev;
        return;
    }
    inverter(root->right, root, leaf, q, ans);
    if(q){
        if(root->left) root->right = root->left;
        else{
        root->right = NULL;
        }
        root->left = prev;
        return;
    }
}
TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
	TreeNode<int>* ans = NULL;
    bool q = 0;
    inverter(root, NULL, leaf, q, ans);
    return ans;
}