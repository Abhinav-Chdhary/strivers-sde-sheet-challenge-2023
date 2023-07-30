#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// TreeNode class definition
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

bool isLeaf(TreeNode<int> *node)
{
    return node->left == nullptr && node->right == nullptr;
}

void leftBoundary(TreeNode<int> *root, vector<int> &res)
{
    root = root->left;
    while (root)
    {
        if (!isLeaf(root))
            res.push_back(root->data);
        if (root->left)
            root = root->left;
        else
            root = root->right;
    }
}

void bottomBoundary(TreeNode<int> *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        bottomBoundary(root->left, res);
    if (root->right)
        bottomBoundary(root->right, res);
}

void rightBoundary(TreeNode<int> *root, vector<int> &res)
{
    root = root->right;
    stack<int> stk;
    while (root)
    {
        if (!isLeaf(root))
            stk.push(root->data);
        if (root->right)
            root = root->right;
        else
            root = root->left;
    }
    while (!stk.empty())
    {
        res.push_back(stk.top());
        stk.pop();
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> res;
    if (!root)
        return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    leftBoundary(root, res);
    bottomBoundary(root, res);
    rightBoundary(root, res);
    return res;
}

int main()
{
    // Create the tree nodes
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(4);
    root->left->right->left = new TreeNode<int>(7);
    root->left->right->right = new TreeNode<int>(8);
    root->right->left = new TreeNode<int>(5);
    root->right->right = new TreeNode<int>(6);

    // Get the boundary traversal of the tree
    vector<int> boundaryTraversal = traverseBoundary(root);

    // Print the boundary traversal
    cout << "Boundary Traversal: ";
    for (int val : boundaryTraversal)
    {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory (deallocate the tree)
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
