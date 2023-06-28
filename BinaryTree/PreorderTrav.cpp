//Recursive
void preorder(vector<int> &res, TreeNode* root){
    if(!root) return;
    res.push_back(root->data);
    preorder(res, root->left);
    preorder(res, root->right);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> res;
    preorder(res, root);
    return res;
}