#include <iostream>
#include <utility>

using namespace std;

// Definition for a binary tree node.
template <typename T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    int suc = -1;
    BinaryTreeNode<int> *cur = root;
    while (cur)
    {
        if (cur->data > key)
        {
            suc = cur->data;
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }

    int pre = -1;
    while (root)
    {
        if (root->data < key)
        {
            pre = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return {pre, suc};
}

int main()
{
    // Create the binary tree manually (you can build it programmatically too).
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(15);
    root->left = new BinaryTreeNode<int>(10);
    root->right = new BinaryTreeNode<int>(20);
    root->left->left = new BinaryTreeNode<int>(8);
    root->left->right = new BinaryTreeNode<int>(12);
    root->right->left = new BinaryTreeNode<int>(17);
    root->right->right = new BinaryTreeNode<int>(25);

    int key = 12;
    pair<int, int> result = predecessorSuccessor(root, key);

    cout << "Key: " << key << endl;
    cout << "Predecessor: " << result.first << endl;
    cout << "Successor: " << result.second << endl;

    // Clean up the dynamically allocated memory (optional but recommended).
    // You may want to use a proper tree destruction function for larger trees.
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
