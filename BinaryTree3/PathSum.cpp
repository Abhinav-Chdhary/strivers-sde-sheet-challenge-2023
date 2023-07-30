#include <iostream>
#include <algorithm>

using namespace std;

// Definition of TreeNode
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T value) : val(value), left(nullptr), right(nullptr) {}
};

// Type alias for long long int
using lli = long long int;

// Function to find the maximum sum path in the binary tree
lli findMaxSumPath(TreeNode<int> *root, long long int &ans)
{
    if (!root)
        return 0;
    lli left = findMaxSumPath(root->left, ans);
    lli right = findMaxSumPath(root->right, ans);
    ans = max(ans, left + right + root->val);
    return root->val + max(left, right);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    lli ans = -1;
    if (!root || !root->left || !root->right)
        return -1;
    findMaxSumPath(root, ans);
    return ans;
}

// Helper function to construct a sample tree for testing
TreeNode<int> *buildSampleTree()
{
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6

    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->right = new TreeNode<int>(6);
    return root;
}

int main()
{
    TreeNode<int> *root = buildSampleTree();

    long long int maxSumPath = findMaxSumPath(root);

    cout << "Maximum sum path: " << maxSumPath << endl;

    // Don't forget to free the memory allocated for the tree
    // (not done here for simplicity)

    return 0;
}
