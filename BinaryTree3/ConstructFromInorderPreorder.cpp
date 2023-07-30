#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node
template <typename T>
struct TreeNode
{
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode<int> *building(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int> &um)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    TreeNode<int> *node = new TreeNode<int>(preorder[preStart]);
    int inRoot = um[node->data];
    int numsLeft = inRoot - inStart;

    node->left = building(preorder, inorder, preStart + 1, preStart + numsLeft, inStart, inRoot - 1, um);
    node->right = building(preorder, inorder, preStart + numsLeft + 1, preEnd, inRoot + 1, inEnd, um);

    return node;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    unordered_map<int, int> um;
    for (int i = 0; i < inorder.size(); i++)
    {
        um[inorder[i]] = i;
    }
    return building(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, um);
}

// Helper function to print the binary tree (preorder traversal)
void printPreorder(TreeNode<int> *root)
{
    if (root)
    {
        cout << root->data << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

int main()
{
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};

    TreeNode<int> *root = buildBinaryTree(inorder, preorder);

    cout << "Preorder traversal of the constructed binary tree: ";
    printPreorder(root);
    cout << endl;

    // Clean up the allocated memory (optional, but good practice)
    // You can write a separate function to deallocate the tree nodes
    // and call it here.

    return 0;
}
