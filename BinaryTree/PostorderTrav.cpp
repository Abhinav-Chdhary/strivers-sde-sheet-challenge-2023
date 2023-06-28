//Recursive
void postorder(vector<int> &res, TreeNode* root){
    if(!root) return;
    postorder(res, root->left);
    postorder(res, root->right);
    res.push_back(root->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> res;
    postorder(res, root);
    return res;
}
//Morris
