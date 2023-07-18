TreeNode<int>* treeCreator(vector<int> &arr, int l, int r){
    if(l>r) return NULL;
    if(l==r){
        TreeNode<int>* node = new TreeNode<int>(arr[l]);
        return node;
    }
    int mid = (l+r)/2;
    TreeNode<int>* node = new TreeNode<int>(arr[mid]);
    node->left = treeCreator(arr, l, mid-1);
    node->right = treeCreator(arr, mid+1, r);
    return node;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return treeCreator(arr, 0, n-1);
}