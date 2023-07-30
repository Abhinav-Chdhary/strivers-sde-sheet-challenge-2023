#include <iostream>
#include <algorithm>
using namespace std;

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

int traverse(TreeNode<int> *root, int &maxi)
{
    if (!root)
        return 0;
    int left = traverse(root->left, maxi);
    int right = traverse(root->right, maxi);
    maxi = max(maxi, left + right);
    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    if (!root)
        return 0;
    int ans = 0;
    traverse(root, ans);
    return ans;
}

int main()
{
    // Sample usage
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    int diameter = diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << diameter << endl;

    // Remember to free the allocated memory to avoid memory leaks
    // Implement a function to delete the tree nodes
    // (not included in this example for simplicity)
    return 0;
}
