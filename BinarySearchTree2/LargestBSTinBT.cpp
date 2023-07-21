class nodeDetails
{
public:
    int maxi, mini, maxSize;
    nodeDetails(int mx, int mn, int sz)
    {
        maxi = mx;
        mini = mn;
        maxSize = sz;
    }
};
nodeDetails finder(TreeNode<int> *root)
{
    if (!root)
        return nodeDetails(INT_MIN, INT_MAX, 0);

    auto left = finder(root->left);
    auto right = finder(root->right);

    if (left.maxi < root->data && root->data < right.mini)
    {
        // It is a BST
        return nodeDetails(max(root->data, right.maxi), min(root->data, left.mini), left.maxSize + right.maxSize + 1);
    }
    else
    {
        // Not a BST
        return nodeDetails(INT_MAX, INT_MIN, max(left.maxSize, right.maxSize));
    }
}

int largestBST(TreeNode<int> *root)
{
    return finder(root).maxSize;
}