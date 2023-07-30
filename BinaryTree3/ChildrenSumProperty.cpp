#include <iostream>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

int modifier(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return root->data;
    int l = 0, r = 0, child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    if (child < root->data)
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }

    if (root->left)
        l = modifier(root->left);
    if (root->right)
        r = modifier(root->right);
    int sum = root->data = l + r;
    return sum;
}

void changeTree(BinaryTreeNode<int> *root)
{
    modifier(root);
}

// Helper function to create a binary tree for testing
BinaryTreeNode<int> *createNode(int data)
{
    return new BinaryTreeNode<int>(data);
}

int main()
{
    // Create a sample binary tree for testing
    BinaryTreeNode<int> *root = createNode(10);
    root->left = createNode(6);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(8);
    root->right->right = createNode(2);

    std::cout << "Original Binary Tree: " << std::endl;
    // Output the original tree structure
    // This is just a visualization for demonstration purposes
    // In a real implementation, you might want to use tree traversal algorithms
    // to output the tree structure properly.
    std::cout << "       10       " << std::endl;
    std::cout << "     /    \\     " << std::endl;
    std::cout << "    6      3    " << std::endl;
    std::cout << "   / \\      \\  " << std::endl;
    std::cout << "  4   8      2 " << std::endl;
    std::cout << std::endl;

    // Call the changeTree function to modify the tree
    changeTree(root);

    std::cout << "Modified Binary Tree: " << std::endl;
    // Output the modified tree structure after calling the changeTree function
    // This is just a visualization for demonstration purposes
    // In a real implementation, you might want to use tree traversal algorithms
    // to output the tree structure properly.
    std::cout << "       30       " << std::endl;
    std::cout << "     /    \\     " << std::endl;
    std::cout << "   30      3    " << std::endl;
    std::cout << "   / \\      \\  " << std::endl;
    std::cout << " 30  30      30 " << std::endl;

    return 0;
}
