int traverse(TreeNode<int> *root, int &maxi){
    if(!root) return 0;
    int left = traverse(root->left, maxi);
    int right = traverse(root->right, maxi);
    maxi = max(maxi, left+right);
    return 1+max(left, right);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    if(!root) return 0;
    int ans=0;
	traverse(root, ans);
    return ans;
}