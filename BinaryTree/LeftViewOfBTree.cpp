#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
struct TreeNode
{
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> getLeftView(TreeNode<int> *root)
{
    if (!root)
        return {};
    queue<TreeNode<int> *> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        int sz = q.size();
        ans.push_back(q.front()->data);
        while (sz--)
        {
            TreeNode<int> *curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return ans;
}

// Helper function to create a binary tree from an array
TreeNode<int> *createBinaryTree(const vector<int> &arr, int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = start + (end - start) / 2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root->left = createBinaryTree(arr, start, mid - 1);
    root->right = createBinaryTree(arr, mid + 1, end);
    return root;
}

int main()
{
    // Example usage of the getLeftView function
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    TreeNode<int> *root = createBinaryTree(arr, 0, arr.size() - 1);

    vector<int> leftView = getLeftView(root);

    cout << "Left View of the Binary Tree: ";
    for (int val : leftView)
    {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the dynamically allocated memory for the tree
    // Assuming you have a function to delete the tree
    // deleteTree(root);

    return 0;
}
