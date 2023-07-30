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

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform an inorder traversal of the binary tree
template <typename T>
void inorder(TreeNode<T> *root, vector<T> &trav)
{
    if (!root)
        return;
    inorder(root->left, trav);
    trav.push_back(root->data);
    inorder(root->right, trav);
}

// Function to find the Kth largest number in the binary tree
template <typename T>
T KthLargestNumber(TreeNode<T> *root, int k)
{
    vector<T> trav;
    inorder(root, trav);
    if (k > trav.size())
        return -1;
    return trav[trav.size() - k];
}

int main()
{
    // Creating the binary tree manually for demonstration
    TreeNode<int> *root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(7);
    root->right = new TreeNode<int>(15);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(9);
    root->right->left = new TreeNode<int>(12);
    root->right->right = new TreeNode<int>(20);

    int k = 3;
    int kthLargest = KthLargestNumber(root, k);

    if (kthLargest != -1)
    {
        cout << "The " << k << "th largest number in the binary tree is: " << kthLargest << endl;
    }
    else
    {
        cout << "The tree does not have " << k << " elements." << endl;
    }

    // Freeing the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
