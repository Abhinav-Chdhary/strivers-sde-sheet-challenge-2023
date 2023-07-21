//O(logn)
void finder(TreeNode<int>* root, int x, int &ans){
    if(!root) return;
    if(root->val<=x){
        ans = max(ans, root->val);
    }
    if(x>root->val) finder(root->right, x, ans);
    if(x<root->val) finder(root->left, x, ans);
}
int floorInBST(TreeNode<int> * root, int x)
{
    int ans = -1;
    finder(root, x, ans);
    return ans;
}