#include <iostream>
#include <vector>
#include <climits>

using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode<int> *treeCreator(vector<int> &preorder, int &index, int key, int min, int max)
{
    if (index >= preorder.size())
    {
        return nullptr;
    }

    TreeNode<int> *node = nullptr;
    int sz = preorder.size();

    if (key > min && key < max)
    {
        node = new TreeNode<int>(key);
        index++;
        if (index < sz)
        {
            node->left = treeCreator(preorder, index, preorder[index], min, key);
        }
        if (index < sz)
        {
            node->right = treeCreator(preorder, index, preorder[index], key, max);
        }
    }

    return node;
}

TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    int ind = 0;
    return treeCreator(preOrder, ind, preOrder[0], INT_MIN, INT_MAX);
}

void printInorder(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    vector<int> preOrder = {10, 5, 1, 7, 40, 50};

    TreeNode<int> *root = preOrderTree(preOrder);

    cout << "Inorder Traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    // Free the memory allocated for the tree nodes (optional).
    // Implement a function to delete the tree if required.

    return 0;
}
