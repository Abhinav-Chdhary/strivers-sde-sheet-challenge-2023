#include <iostream>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    if (!root)
        return false;
    if (searchInBST(root->left, x))
        return true;
    if (root->data == x)
        return true;
    if (searchInBST(root->right, x))
        return true;
    return false;
}

// Function to insert a new node into the BST
BinaryTreeNode<int> *insertInBST(BinaryTreeNode<int> *root, int value)
{
    if (!root)
    {
        return new BinaryTreeNode<int>(value);
    }

    if (value <= root->data)
    {
        root->left = insertInBST(root->left, value);
    }
    else
    {
        root->right = insertInBST(root->right, value);
    }

    return root;
}

// Function to create a sample Binary Search Tree for testing
BinaryTreeNode<int> *createBST()
{
    BinaryTreeNode<int> *root = nullptr;
    root = insertInBST(root, 8);
    insertInBST(root, 3);
    insertInBST(root, 10);
    insertInBST(root, 1);
    insertInBST(root, 6);
    insertInBST(root, 14);
    insertInBST(root, 4);
    insertInBST(root, 7);
    insertInBST(root, 13);

    return root;
}

int main()
{
    // Create a sample BST
    BinaryTreeNode<int> *root = createBST();

    // Test the searchInBST function
    int target = 7;
    if (searchInBST(root, target))
    {
        std::cout << target << " is present in the BST." << std::endl;
    }
    else
    {
        std::cout << target << " is not present in the BST." << std::endl;
    }

    target = 9;
    if (searchInBST(root, target))
    {
        std::cout << target << " is present in the BST." << std::endl;
    }
    else
    {
        std::cout << target << " is not present in the BST." << std::endl;
    }

    // Clean up the memory (not necessary for this example, but good practice)
    // You may use a proper BST deletion function to release the memory.
    return 0;
}
