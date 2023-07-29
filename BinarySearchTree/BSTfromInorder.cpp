#include <iostream>
#include <vector>

using namespace std;

// TreeNode structure
template <typename T>
struct TreeNode
{
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) : data(val), left(NULL), right(NULL) {}
};

// Function to create a BST from a sorted array
TreeNode<int> *treeCreator(vector<int> &arr, int l, int r)
{
    if (l > r)
        return NULL;
    if (l == r)
    {
        TreeNode<int> *node = new TreeNode<int>(arr[l]);
        return node;
    }
    int mid = (l + r) / 2;
    TreeNode<int> *node = new TreeNode<int>(arr[mid]);
    node->left = treeCreator(arr, l, mid - 1);
    node->right = treeCreator(arr, mid + 1, r);
    return node;
}

// Function to create a BST from a sorted array (Driver function)
TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    return treeCreator(arr, 0, n - 1);
}

// Helper function to print the BST in Inorder traversal
void printInorder(TreeNode<int> *root)
{
    if (root)
    {
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}

int main()
{
    vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Create the BST from the sorted array
    TreeNode<int> *root = sortedArrToBST(sortedArray, sortedArray.size());

    // Print the BST in Inorder traversal
    cout << "Inorder traversal of the BST: ";
    printInorder(root);
    cout << endl;

    // Clean up - free memory
    // (You can implement a separate function for deleting the BST to avoid code repetition)
    // This is not necessary for the test case, but it's good practice to free allocated memory.
    delete root;

    return 0;
}
