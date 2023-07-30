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

// Function to invert the binary tree
void inverter(TreeNode<int> *root, TreeNode<int> *prev, TreeNode<int> *leaf, bool &q, TreeNode<int> *&ans)
{
    if (!root)
        return;
    if (root->data == leaf->data)
    {
        root->left = prev;
        q = true;
        ans = root;
        return;
    }
    inverter(root->left, root, leaf, q, ans);
    if (q)
    {
        root->left = prev;
        return;
    }
    inverter(root->right, root, leaf, q, ans);
    if (q)
    {
        if (root->left)
            root->right = root->left;
        else
        {
            root->right = nullptr;
        }
        root->left = prev;
        return;
    }
}

TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    TreeNode<int> *ans = nullptr;
    bool q = false;
    inverter(root, nullptr, leaf, q, ans);
    return ans;
}

// Helper function to create a binary tree
TreeNode<int> *createBinaryTree()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);
    return root;
}

int main()
{
    TreeNode<int> *root = createBinaryTree();
    TreeNode<int> *leaf = root->left->left; // Selecting a leaf node (4 in this case) to be the root of the inverted tree

    std::cout << "Original Binary Tree:" << std::endl;
    // Print the original binary tree
    // Output should be: 1 2 4 5 3 6 7
    //        1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7
    std::cout << root->data << " ";
    if (root->left)
        std::cout << root->left->data << " ";
    if (root->right)
        std::cout << root->right->data << " ";
    if (root->left && root->left->left)
        std::cout << root->left->left->data << " ";
    if (root->left && root->left->right)
        std::cout << root->left->right->data << " ";
    if (root->right && root->right->left)
        std::cout << root->right->left->data << " ";
    if (root->right && root->right->right)
        std::cout << root->right->right->data << " ";
    std::cout << std::endl;

    TreeNode<int> *invertedRoot = invertBinaryTree(root, leaf);

    std::cout << "Inverted Binary Tree:" << std::endl;
    // Print the inverted binary tree
    // Output should be: 4 2 5 1 6 3 7
    //        4
    //       / \
    //      2   3
    //     / \ / \
    //    5  1 6  7
    std::cout << invertedRoot->data << " ";
    if (invertedRoot->left)
        std::cout << invertedRoot->left->data << " ";
    if (invertedRoot->right)
        std::cout << invertedRoot->right->data << " ";
    if (invertedRoot->left && invertedRoot->left->left)
        std::cout << invertedRoot->left->left->data << " ";
    if (invertedRoot->left && invertedRoot->left->right)
        std::cout << invertedRoot->left->right->data << " ";
    if (invertedRoot->right && invertedRoot->right->left)
        std::cout << invertedRoot->right->left->data << " ";
    if (invertedRoot->right && invertedRoot->right->right)
        std::cout << invertedRoot->right->right->data << " ";
    std::cout << std::endl;

    return 0;
}
