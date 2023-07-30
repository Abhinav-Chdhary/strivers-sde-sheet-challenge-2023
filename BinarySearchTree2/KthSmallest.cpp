#include <iostream>
#include <vector>

template <typename T>
struct TreeNode
{
    T data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode<int> *root, std::vector<int> &trav)
{
    if (!root)
        return;
    inorder(root->left, trav);
    trav.push_back(root->data);
    inorder(root->right, trav);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    std::vector<int> trav;
    inorder(root, trav);
    if (k > trav.size())
        return -1;
    return trav[k - 1];
}

int main()
{
    // Create the binary search tree
    TreeNode<int> *root = new TreeNode<int>(5);
    root->left = new TreeNode<int>(3);
    root->right = new TreeNode<int>(7);
    root->left->left = new TreeNode<int>(2);
    root->left->right = new TreeNode<int>(4);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(8);

    // Test the kthSmallest function
    int k = 3;
    int kthSmallestValue = kthSmallest(root, k);

    if (kthSmallestValue != -1)
    {
        std::cout << "The " << k << "th smallest element is: " << kthSmallestValue << std::endl;
    }
    else
    {
        std::cout << "Invalid k value! The tree has less than " << k << " elements." << std::endl;
    }

    // Clean up the dynamically allocated memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
