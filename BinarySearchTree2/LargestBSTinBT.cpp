#include <iostream>
#include <algorithm>
#include <climits>

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

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
        return nodeDetails(std::max(root->data, right.maxi), std::min(root->data, left.mini), left.maxSize + right.maxSize + 1);
    }
    else
    {
        // Not a BST
        return nodeDetails(INT_MAX, INT_MIN, std::max(left.maxSize, right.maxSize));
    }
}

int largestBST(TreeNode<int> *root)
{
    return finder(root).maxSize;
}

int main()
{
    // Construct the binary tree for testing
    TreeNode<int> *root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(5);
    root->right = new TreeNode<int>(15);
    root->left->left = new TreeNode<int>(1);
    root->left->right = new TreeNode<int>(8);
    root->right->right = new TreeNode<int>(7);

    int result = largestBST(root);
    std::cout << "Size of the largest BST: " << result << std::endl;

    // Deallocate memory (optional, but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
