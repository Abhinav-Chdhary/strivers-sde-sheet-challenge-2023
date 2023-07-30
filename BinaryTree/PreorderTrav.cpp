#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Recursive Preorder Traversal
void preorder(vector<int> &res, TreeNode *root)
{
    if (!root)
        return;
    res.push_back(root->data);
    preorder(res, root->left);
    preorder(res, root->right);
}

vector<int> getPreOrderTraversalRecursive(TreeNode *root)
{
    vector<int> res;
    preorder(res, root);
    return res;
}

// Morris Traversal Preorder
vector<int> getPreOrderTraversalMorris(TreeNode *root)
{
    vector<int> res;
    TreeNode *curr = root;

    while (curr)
    {
        if (!curr->left)
        {
            res.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            TreeNode *predecessor = curr->left;
            while (predecessor->right && predecessor->right != curr)
            {
                predecessor = predecessor->right;
            }

            if (!predecessor->right)
            {
                res.push_back(curr->data);
                predecessor->right = curr;
                curr = curr->left;
            }
            else
            {
                predecessor->right = nullptr;
                curr = curr->right;
            }
        }
    }

    return res;
}

// Helper function to create a binary tree from an array representation
TreeNode *createTreeFromArray(const vector<int> &arr, int index)
{
    if (index >= arr.size() || arr[index] == -1)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(arr[index]);
    root->left = createTreeFromArray(arr, 2 * index + 1);
    root->right = createTreeFromArray(arr, 2 * index + 2);
    return root;
}

int main()
{
    // Example usage:
    vector<int> arr = {1, 2, 3, 4, 5, -1, -1};
    TreeNode *root = createTreeFromArray(arr, 0);

    // Recursive Preorder Traversal
    vector<int> resRecursive = getPreOrderTraversalRecursive(root);
    cout << "Recursive Preorder Traversal: ";
    for (int num : resRecursive)
    {
        cout << num << " ";
    }
    cout << endl;

    // Morris Traversal Preorder
    vector<int> resMorris = getPreOrderTraversalMorris(root);
    cout << "Morris Traversal Preorder: ";
    for (int num : resMorris)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
