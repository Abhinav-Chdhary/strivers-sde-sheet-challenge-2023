TreeNode<int>* LCAfinder(TreeNode<int>* root, TreeNode<int>* x, TreeNode<int>* y){
    if(!root || root->data==x->data || root->data==y->data)
        return root;
    TreeNode<int>* left = LCAfinder(root->left, x, y);
    TreeNode<int>* right = LCAfinder(root->right, x, y);
    if(left==NULL)
        return right;
    else if(right==NULL)
        return left;
    else 
        return root;
    
}
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	return LCAfinder(root, P, Q);
}