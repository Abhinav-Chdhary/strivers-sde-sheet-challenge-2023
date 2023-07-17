lli findMaxSumPath(TreeNode<int>* root, long long int &ans){
    if(!root) return 0;
    lli left = findMaxSumPath(root->left, ans);
    lli right =findMaxSumPath(root->right, ans);
    ans = max(ans, left+right+root->val);
    return root->val+max(left, right);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    lli ans=-1;
    if(!root || !root->left || !root->right) return -1;
    findMaxSumPath(root, ans);
    return ans;
}