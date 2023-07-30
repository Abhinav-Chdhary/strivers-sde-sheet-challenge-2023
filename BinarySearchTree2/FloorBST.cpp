#include <iostream>

// Definition for a binary tree node
template <typename T>
struct TreeNode
{
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}
};

// Function to find the floor of x in a binary search tree (BST)
// Approach: O(logn)
void finder(TreeNode<int> *root, int x, int &ans)
{
    if (!root)
        return;
    if (root->val <= x)
    {
        ans = std::max(ans, root->val);
    }
    if (x > root->val)
        finder(root->right, x, ans);
    if (x < root->val)
        finder(root->left, x, ans);
}

// Function to find the floor of x in a binary search tree (BST)
// Approach: O(logn)
int floorInBST(TreeNode<int> *root, int x)
{
    int ans = -1;
    finder(root, x, ans);
    return ans;
}

int main()
{
    // Sample binary search tree (BST)
    //        10
    //       /   \
    //      5     15
    //     / \   /  \
    //    2   8 12   20
    TreeNode<int> *root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(5);
    root->right = new TreeNode<int>(15);
    root->left->left = new TreeNode<int>(2);
    root->left->right = new TreeNode<int>(8);
    root->right->left = new TreeNode<int>(12);
    root->right->right = new TreeNode<int>(20);

    int x = 9;
    int floorValue = floorInBST(root, x);
    std::cout << "Floor of " << x << " in the BST is: " << floorValue << std::endl;

    // Clean up the memory (you can implement a separate function for this in a real application)
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
