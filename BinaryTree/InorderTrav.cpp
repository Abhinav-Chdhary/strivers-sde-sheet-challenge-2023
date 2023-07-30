#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Recursive approach
void inorder(std::vector<int> &res, TreeNode *root)
{
    if (!root)
        return;
    inorder(res, root->left);
    res.push_back(root->data);
    inorder(res, root->right);
}

std::vector<int> getInOrderTraversal(TreeNode *root)
{
    std::vector<int> res;
    inorder(res, root);
    return res;
}

// Helper function to insert nodes into the binary tree
TreeNode *insert(TreeNode *root, int data)
{
    if (!root)
    {
        return new TreeNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

int main()
{
    // Driver code to test the in-order traversal function
    TreeNode *root = nullptr;

    // Insert elements into the binary tree
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    // Get in-order traversal of the binary tree
    std::vector<int> inorderTraversal = getInOrderTraversal(root);

    // Display the in-order traversal result
    std::cout << "In-order Traversal: ";
    for (int val : inorderTraversal)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
