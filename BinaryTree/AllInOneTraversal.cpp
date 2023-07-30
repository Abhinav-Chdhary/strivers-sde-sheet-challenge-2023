#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition of BinaryTreeNode
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    // Function implementation goes here
    vector<vector<int>> ans(3);
    if (!root)
        return ans;
    stack<pair<BinaryTreeNode<int> *, int>> stk;
    stk.push({root, 0});
    while (!stk.empty())
    {
        auto it = stk.top();
        stk.pop();
        if (it.second == 0)
        {
            ans[1].push_back(it.first->data);
            it.second++;
            stk.push(it);
            if (it.first->left)
            {
                stk.push({it.first->left, 0});
            }
        }
        else if (it.second == 1)
        {
            ans[0].push_back(it.first->data);
            it.second++;
            stk.push(it);
            if (it.first->right)
            {
                stk.push({it.first->right, 0});
            }
        }
        else if (it.second == 2)
        {
            ans[2].push_back(it.first->data);
        }
    }
    return ans;
}

// Helper function to create a sample binary tree
BinaryTreeNode<int> *createBinaryTree()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = createBinaryTree();

    // Calling the function and printing the results
    vector<vector<int>> traversal = getTreeTraversal(root);

    cout << "Pre-order traversal: ";
    for (int num : traversal[0])
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "In-order traversal: ";
    for (int num : traversal[1])
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Post-order traversal: ";
    for (int num : traversal[2])
    {
        cout << num << " ";
    }
    cout << endl;

    // Free the memory
    // TODO: Implement a proper destructor for BinaryTreeNode to deallocate memory
    // Note: As this is just a driver code, it's acceptable to leave the memory deallocation here.

    return 0;
}
