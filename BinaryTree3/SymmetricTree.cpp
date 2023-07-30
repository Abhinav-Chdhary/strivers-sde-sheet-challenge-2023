#include <iostream>

// Binary Tree Node Definition
template <typename T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T val) : data(val), left(NULL), right(NULL) {}
};

// Function to check if a tree is symmetric
bool testSymmetric(BinaryTreeNode<int> *l, BinaryTreeNode<int> *r)
{
    if (l == NULL && r == NULL)
        return true;
    else if (l == NULL || r == NULL)
        return false;
    if (l->data != r->data)
        return false;
    return testSymmetric(l->left, r->right) && testSymmetric(l->right, r->left);
}

bool isSymmetric(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    return testSymmetric(root->left, root->right);
}

// Helper function to create a Binary Tree
BinaryTreeNode<int> *createNode(int data)
{
    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
    return newNode;
}

int main()
{
    // Create the Binary Tree
    BinaryTreeNode<int> *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(4);
    root->right->right = createNode(3);

    // Call the isSymmetric function and check the result
    if (isSymmetric(root))
        std::cout << "The Binary Tree is symmetric." << std::endl;
    else
        std::cout << "The Binary Tree is not symmetric." << std::endl;

    // Free the memory
    // You can implement a function to delete the entire tree to avoid memory leaks.

    return 0;
}
