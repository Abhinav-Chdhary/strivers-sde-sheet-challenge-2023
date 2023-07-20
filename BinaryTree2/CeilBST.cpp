//O(logn)
void finder(BinaryTreeNode<int>* root, int x, int &ans){
    if(!root) return;
    if(root->data>=x){
        ans = min(ans, root->data);
    }
    if(x>root->data) finder(root->right, x, ans);
    if(x<root->data) finder(root->left, x, ans);
}
int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = INT_MAX;
    finder(node, x, ans);
    return ans==INT_MAX? -1: ans;
}