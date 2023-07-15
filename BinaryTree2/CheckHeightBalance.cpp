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