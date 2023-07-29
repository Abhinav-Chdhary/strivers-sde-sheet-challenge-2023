#include <iostream>

// TreeNode structure
template <typename T>
struct TreeNode
{
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the Lowest Common Ancestor (LCA)
template <typename T>
TreeNode<T> *LCAfinder(TreeNode<T> *root, TreeNode<T> *x, TreeNode<T> *y)
{
    if (!root || root->data == x->data || root->data == y->data)
        return root;

    TreeNode<T> *left = LCAfinder(root->left, x, y);
    TreeNode<T> *right = LCAfinder(root->right, x, y);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
}

// Function to find LCA in a Binary Search Tree (BST)
template <typename T>
TreeNode<T> *LCAinaBST(TreeNode<T> *root, TreeNode<T> *P, TreeNode<T> *Q)
{
    return LCAfinder(root, P, Q);
}

int main()
{
    // Create a Binary Search Tree (BST)
    TreeNode<int> *root = new TreeNode<int>(5);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(7);
    root->left->left = new TreeNode<int>(1);
    root->left->right = new TreeNode<int>(3);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(8);

    // Nodes for which we want to find the LCA
    TreeNode<int> *nodeP = root->left;  // Node with value 2
    TreeNode<int> *nodeQ = root->right; // Node with value 7

    // Find the LCA
    TreeNode<int> *lca = LCAinaBST(root, nodeP, nodeQ);

    // Print the LCA value
    if (lca)
        std::cout << "Lowest Common Ancestor: " << lca->data << std::endl;
    else
        std::cout << "One or both nodes not found in the BST." << std::endl;

    // Clean up memory (optional, depending on your use case)
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
