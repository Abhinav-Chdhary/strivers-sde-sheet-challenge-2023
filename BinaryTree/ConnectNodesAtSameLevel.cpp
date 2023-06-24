void connectNodes(BinaryTreeNode< int > *root) {
    if(!root) return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            BinaryTreeNode<int>* curr = q.front();
            q.pop();
            if(sz)
             curr->next = q.front();
            else curr->next = NULL;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
}