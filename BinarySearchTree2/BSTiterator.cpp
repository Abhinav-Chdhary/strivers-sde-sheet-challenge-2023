class BSTiterator
{
    stack<int> stk;
    private:
    void inorder(TreeNode<int>* root){
        if(!root) return ;
        inorder(root->right);
        stk.push(root->data);
        inorder(root->left);
    }
    public:
    BSTiterator(TreeNode<int> *root)
    {
        inorder(root);
    }

    int next()
    {
        int val = stk.top();
        stk.pop();
        return val;
    }

    bool hasNext()
    {
        return !stk.empty();
    }
};