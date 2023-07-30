#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode<int> *helper(vector<int> &inorder, int x, int y, vector<int> &postorder, int a, int b)
{
    if (x > y || a > b)
        return NULL;
    TreeNode<int> *node = new TreeNode<int>(postorder[b]);
    // st means start_index
    int st = x;
    while (inorder[st] != node->data)
        st++;
    node->left = helper(inorder, x, st - 1, postorder, a, a + st - x - 1);
    node->right = helper(inorder, st + 1, y, postorder, a + st - x, b - 1);
    return node;
}

TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inOrder)
{
    return helper(inOrder, 0, inOrder.size() - 1, postOrder, 0, postOrder.size() - 1);
}

// Function to print the inorder traversal of a binary tree
void inorderTraversal(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Function to delete a binary tree to free memory
void deleteTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    // Example input
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    // Construct the binary tree
    TreeNode<int> *root = getTreeFromPostorderAndInorder(postorder, inorder);

    // Print the inorder traversal of the constructed tree
    cout << "Inorder Traversal of the Constructed Binary Tree: ";
    inorderTraversal(root);
    cout << endl;

    // Clean up and delete the binary tree
    deleteTree(root);

    return 0;
}
