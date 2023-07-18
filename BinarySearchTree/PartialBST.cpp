bool validateBST(BinaryTreeNode<int> *root) {
    if(!root) return true;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BinaryTreeNode<int>* cur = q.front();
        q.pop();
        if(cur->left){
            if(cur->left->data > cur->data) return false;
            q.push(cur->left);
        }
        if(cur->right){
            if(cur->right->data < cur->data) return false;
            q.push(cur->right);
        }
    }
    return true;
}