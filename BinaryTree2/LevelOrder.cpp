#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
template <typename T>
class BinaryTreeNode
{
public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to get the level-order traversal of a binary tree
template <typename T>
vector<T> getLevelOrder(BinaryTreeNode<T> *root)
{
    vector<T> res;
    if (!root)
        return res;
    queue<BinaryTreeNode<T> *> q;
    q.push(root);

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            BinaryTreeNode<T> *curr = q.front();
            q.pop();
            res.push_back(curr->val);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return res;
}

int main()
{
    // Create a sample binary tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);

    // Get the level-order traversal of the binary tree
    vector<int> levelOrder = getLevelOrder(root);

    // Display the result
    cout << "Level-Order Traversal: ";
    for (int val : levelOrder)
    {
        cout << val << " ";
    }
    cout << endl;

    // Clean up - delete the binary tree nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
