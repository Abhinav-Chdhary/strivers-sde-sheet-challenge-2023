#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Recursive postorder traversal
void postorder(vector<int> &res, TreeNode *root)
{
    if (!root)
        return;
    postorder(res, root->left);
    postorder(res, root->right);
    res.push_back(root->data);
}

vector<int> getPostOrderTraversalRecursive(TreeNode *root)
{
    vector<int> res;
    postorder(res, root);
    return res;
}

// Morris traversal
vector<int> getPostOrderTraversalMorris(TreeNode *root)
{
    vector<int> res;

    if (!root)
        return res;

    TreeNode *current = root;
    TreeNode *prev;

    while (current)
    {
        if (!current->right)
        {
            res.push_back(current->data);
            current = current->left;
        }
        else
        {
            prev = current->right;
            while (prev->left && prev->left != current)
            {
                prev = prev->left;
            }

            if (!prev->left)
            {
                prev->left = current;
                res.push_back(current->data);
                current = current->right;
            }
            else
            {
                prev->left = nullptr;
                current = current->left;
            }
        }
    }

    reverse(res.begin(), res.end()); // Reversing the result to get postorder traversal
    return res;
}

int main()
{
    // Build a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Recursive Postorder Traversal: ";
    vector<int> res_recursive = getPostOrderTraversalRecursive(root);
    for (int val : res_recursive)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Morris Postorder Traversal: ";
    vector<int> res_morris = getPostOrderTraversalMorris(root);
    for (int val : res_morris)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
