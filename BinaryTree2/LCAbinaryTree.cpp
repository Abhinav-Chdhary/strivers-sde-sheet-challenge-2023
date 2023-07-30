#include <iostream>

// TreeNode class definition (assuming it's already defined)
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the common ancestor of two nodes in a binary tree
TreeNode<int> *finder(TreeNode<int> *root, int x, int y)
{
    if (!root || root->data == x || root->data == y)
        return root;

    TreeNode<int> *left = finder(root->left, x, y);
    TreeNode<int> *right = finder(root->right, x, y);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
}

// Function to find the lowest common ancestor of two nodes in a binary tree
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    return finder(root, x, y)->data;
}

// Helper function to create a binary tree
TreeNode<int> *createBinaryTree()
{
    TreeNode<int> *root = new TreeNode<int>(3);
    root->left = new TreeNode<int>(5);
    root->right = new TreeNode<int>(1);
    root->left->left = new TreeNode<int>(6);
    root->left->right = new TreeNode<int>(2);
    root->right->left = new TreeNode<int>(0);
    root->right->right = new TreeNode<int>(8);
    root->left->right->left = new TreeNode<int>(7);
    root->left->right->right = new TreeNode<int>(4);
    return root;
}

int main()
{
    // Create a sample binary tree
    TreeNode<int> *root = createBinaryTree();

    // Test cases to find the lowest common ancestor of two nodes
    int x, y;

    // Test case 1
    x = 5;
    y = 1;
    int lca = lowestCommonAncestor(root, x, y);
    std::cout << "Lowest Common Ancestor of " << x << " and " << y << ": " << lca << std::endl;

    // Test case 2
    x = 6;
    y = 4;
    lca = lowestCommonAncestor(root, x, y);
    std::cout << "Lowest Common Ancestor of " << x << " and " << y << ": " << lca << std::endl;

    // Test case 3
    x = 7;
    y = 8;
    lca = lowestCommonAncestor(root, x, y);
    std::cout << "Lowest Common Ancestor of " << x << " and " << y << ": " << lca << std::endl;

    // Remember to deallocate the memory used by the binary tree
    // You can create a function to delete the tree nodes if needed.

    return 0;
}
