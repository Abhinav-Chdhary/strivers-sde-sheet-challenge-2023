vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> res; 
    if(!root) return res;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        int sz=q.size();
        for(int i=0; i<sz; i++){
            BinaryTreeNode<int>* curr = q.front();
            q.pop();
            res.push_back(curr->val);

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return res;
}