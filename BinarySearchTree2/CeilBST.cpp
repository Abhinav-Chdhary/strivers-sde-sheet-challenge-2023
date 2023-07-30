#include <iostream>
#include <climits>

// BinaryTreeNode class definition
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

// Helper function to construct a binary tree from an array
template <typename T>
BinaryTreeNode<T> *constructBinaryTree(T arr[], int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    BinaryTreeNode<T> *root = new BinaryTreeNode<T>(arr[mid]);
    root->left = constructBinaryTree(arr, start, mid - 1);
    root->right = constructBinaryTree(arr, mid + 1, end);
    return root;
}

// O(logn)
template <typename T>
void finder(BinaryTreeNode<T> *root, T x, T &ans)
{
    if (!root)
        return;
    if (root->data >= x)
    {
        ans = std::min(ans, root->data);
    }
    if (x > root->data)
        finder(root->right, x, ans);
    if (x < root->data)
        finder(root->left, x, ans);
}

// O(logn)
template <typename T>
T findCeil(BinaryTreeNode<T> *node, T x)
{
    T ans = INT_MAX;
    finder(node, x, ans);
    return (ans == INT_MAX) ? -1 : ans;
}

int main()
{
    // Example usage:
    int arr[] = {1, 4, 7, 10, 13, 16, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    BinaryTreeNode<int> *root = constructBinaryTree(arr, 0, n - 1);

    int x = 8;
    int ceilValue = findCeil(root, x);
    if (ceilValue != -1)
        std::cout << "The ceil of " << x << " is " << ceilValue << std::endl;
    else
        std::cout << "There is no ceil for " << x << " in the tree." << std::endl;

    // Clean up the dynamically allocated memory
    // Implement a function to delete the binary tree
    // if needed to avoid memory leaks.

    return 0;
}
