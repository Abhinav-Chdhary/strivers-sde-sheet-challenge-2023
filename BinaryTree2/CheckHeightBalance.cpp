#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

// Definition for a binary tree node.
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Approach 1: Using recursive approach to check if a binary tree is balanced or not
int traverse(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;
    int left = traverse(root->left);
    if (left == -1)
        return -1;
    int right = traverse(root->right);
    if (right == -1 || abs(left - right) > 1)
        return -1;
    return 1 + max(left, right);
}

bool isBalancedBT(BinaryTreeNode<int> *root)
{
    return traverse(root) != -1;
}

// Approach 2: Using iterative approach to check if a binary tree is balanced or not
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

bool isBalanced(TreeNode *root)
{
    if (!root)
        return true;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
        int left = height(cur->left);
        int right = height(cur->right);
        if (abs(left - right) > 1)
            return false;
    }
    return true;
}

int height(TreeNode *root)
{
    if (!root)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left, right);
}

int main()
{
    // Creating the binary tree
    BinaryTreeNode<int> *rootBT = new BinaryTreeNode<int>(1);
    rootBT->left = new BinaryTreeNode<int>(2);
    rootBT->right = new BinaryTreeNode<int>(3);
    rootBT->left->left = new BinaryTreeNode<int>(4);
    rootBT->left->right = new BinaryTreeNode<int>(5);
    rootBT->right->left = new BinaryTreeNode<int>(6);
    rootBT->right->right = new BinaryTreeNode<int>(7);

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Checking if the binary tree is balanced or not using both approaches
    if (isBalancedBT(rootBT))
        cout << "Binary Tree is balanced (using recursive approach)." << endl;
    else
        cout << "Binary Tree is not balanced (using recursive approach)." << endl;

    if (isBalanced(root))
        cout << "Binary Tree is balanced (using iterative approach)." << endl;
    else
        cout << "Binary Tree is not balanced (using iterative approach)." << endl;

    return 0;
}
