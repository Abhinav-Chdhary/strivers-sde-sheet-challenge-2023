#include <iostream>

// Definition for a binary tree node
template <typename T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T val) : data(val), left(NULL), right(NULL) {}
};

// Function to convert a Binary Tree to a Doubly Linked List (DLL)
void solve(BinaryTreeNode<int> *root, BinaryTreeNode<int> *&head, BinaryTreeNode<int> *&prev)
{
    if (!root)
        return;

    // Convert left subtree to DLL
    solve(root->left, head, prev);

    // Current root node is being inserted into the DLL
    if (!prev)
    {
        head = root;
        prev = root;
    }
    else
    {
        prev->right = root;
        root->left = prev;
        prev = prev->right;
    }

    // Convert right subtree to DLL
    solve(root->right, head, prev);
}

BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *root)
{
    BinaryTreeNode<int> *head = NULL;
    BinaryTreeNode<int> *prev = NULL;
    solve(root, head, prev);

    return head;
}

// Helper function to print the elements of the Doubly Linked List
void printDLL(BinaryTreeNode<int> *head)
{
    BinaryTreeNode<int> *current = head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->right;
    }
    std::cout << std::endl;
}

int main()
{
    // Create a sample Binary Tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(10);
    root->left = new BinaryTreeNode<int>(5);
    root->right = new BinaryTreeNode<int>(15);
    root->left->left = new BinaryTreeNode<int>(2);
    root->left->right = new BinaryTreeNode<int>(7);
    root->right->left = new BinaryTreeNode<int>(12);
    root->right->right = new BinaryTreeNode<int>(20);

    // Convert Binary Tree to DLL
    BinaryTreeNode<int> *head = BTtoDLL(root);

    // Print the elements of the Doubly Linked List
    printDLL(head);

    // Don't forget to deallocate the memory to prevent memory leaks
    // Deallocate the Binary Tree (use any appropriate deallocation function)
    // ...

    return 0;
}
