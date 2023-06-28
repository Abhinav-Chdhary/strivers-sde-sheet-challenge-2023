bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(!root) return false;
    if(searchInBST(root->left, x)) return true;
    if(root->data==x) return true;
    if(searchInBST(root->right, x)) return true;
    return false;
}