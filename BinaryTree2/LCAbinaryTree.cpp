TreeNode<int>* finder(TreeNode<int>* root, int x, int y){
    if(!root || root->data==x || root->data==y)
        return root;
    TreeNode<int>* left = finder(root->left, x, y);
    TreeNode<int>* right = finder(root->right, x, y);
    if(left==NULL)
        return right;
    else if(right==NULL)
        return left;
    else 
        return root;
    
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	return finder(root, x, y)->data;
}