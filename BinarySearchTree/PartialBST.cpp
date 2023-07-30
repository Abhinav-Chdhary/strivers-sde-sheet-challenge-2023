#include <iostream>
#include <queue>

template <typename T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
};

bool validateBST(BinaryTreeNode<int> *root)
{
    if (!root)
        return true;
    std::queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *cur = q.front();
        q.pop();

        if (cur->left)
        {
            if (cur->left->data > cur->data)
                return false;
            q.push(cur->left);
        }

        if (cur->right)
        {
            if (cur->right->data < cur->data)
                return false;
            q.push(cur->right);
        }
    }
    return true;
}

int main()
{
    // Sample binary tree to test the validateBST function
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(5);
    root->left = new BinaryTreeNode<int>(3);
    root->right = new BinaryTreeNode<int>(7);
    root->left->left = new BinaryTreeNode<int>(2);
    root->left->right = new BinaryTreeNode<int>(4);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(8);

    // Validate if the given binary tree is a valid BST
    if (validateBST(root))
    {
        std::cout << "The binary tree is a valid BST." << std::endl;
    }
    else
    {
        std::cout << "The binary tree is NOT a valid BST." << std::endl;
    }

    // Clean up the dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
