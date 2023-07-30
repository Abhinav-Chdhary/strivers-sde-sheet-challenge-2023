#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// TreeNode Definition
template <typename T>
struct TreeNode
{
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform Vertical Order Traversal
template <typename T>
vector<T> verticalOrderTraversal(TreeNode<T> *root)
{
    vector<T> ans;
    if (!root)
        return ans;
    map<int, vector<T>> lineToList;
    queue<pair<TreeNode<T> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        lineToList[it.second].push_back(it.first->data);
        if (it.first->left)
            q.push({it.first->left, it.second - 1});
        if (it.first->right)
            q.push({it.first->right, it.second + 1});
    }
    for (auto list : lineToList)
    {
        for (auto element : list.second)
        {
            ans.push_back(element);
        }
    }
    return ans;
}

int main()
{
    // Creating the tree manually for demonstration
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    // Calling the verticalOrderTraversal function
    vector<int> result = verticalOrderTraversal(root);

    // Printing the result
    cout << "Vertical Order Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the allocated memory (not necessary for the driver demonstration, but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
