#include <iostream>
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

int getMaxWidth(TreeNode<int> *root)
{
    int ans = 0;
    if (!root)
        return ans;
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        ans = max(ans, sz);
        while (sz--)
        {
            auto it = q.front();
            q.pop();
            if (it->left)
                q.push(it->left);
            if (it->right)
                q.push(it->right);
        }
    }
    return ans;
}

int main()
{
    // Create a sample binary tree
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->right = new TreeNode<int>(8);
    root->right->right->left = new TreeNode<int>(6);
    root->right->right->right = new TreeNode<int>(7);

    // Call the function and display the result
    int maxWidth = getMaxWidth(root);
    cout << "Maximum width of the binary tree: " << maxWidth << endl;

    // Clean up the memory (optional)
    // Implementing a tree cleanup function is recommended in real applications.

    return 0;
}
