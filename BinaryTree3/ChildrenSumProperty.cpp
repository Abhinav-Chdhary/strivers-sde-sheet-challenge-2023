int modifier(BinaryTreeNode < int > * root){
    if(!root) return 0;
    if(!root->left && !root->right) return root->data;
    int l = 0, r = 0, child = 0;
    if(root->left) child+=root->left->data;
    if(root->right) child+=root->right->data;

    if(child<root->data){
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }

    if(root->left) l = modifier(root->left);
    if(root->right) r = modifier(root->right);
    int sum = root->data = l+r;
    return sum;
}
void changeTree(BinaryTreeNode < int > * root) {
    modifier(root);
} 