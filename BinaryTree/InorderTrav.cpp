//Recursive
void inorder(vector<int> &res, TreeNode* root){
    if(!root) return;
    inorder(res, root->left);
    res.push_back(root->data);
    inorder(res, root->right);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> res;
    inorder(res, root);
    return res;
}