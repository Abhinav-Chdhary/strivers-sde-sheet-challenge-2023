#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition for a binary tree node
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

// Function to create a sample binary tree
TreeNode<int> *createSampleTree()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(4);
    root->left->right->right = new TreeNode<int>(5);
    root->left->right->right->right = new TreeNode<int>(6);
    return root;
}

vector<int> getTopView(TreeNode<int> *root)
{
    if (!root)
        return {};
    // to store the first node of every vertical line
    map<int, int> lineToNode;
    // to traverse the queue
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    // to store the ans
    vector<int> ans;

    while (!q.empty())
    {
        TreeNode<int> *curr = q.front().first;
        int line = q.front().second;
        if (lineToNode.find(line) == lineToNode.end())
        {
            lineToNode[line] = curr->val;
        }
        q.pop();
        if (curr->left)
            q.push({curr->left, line - 1});
        if (curr->right)
            q.push({curr->right, line + 1});
    }
    for (auto item : lineToNode)
    {
        ans.push_back(item.second);
    }
    return ans;
}

int main()
{
    // Create a sample binary tree
    TreeNode<int> *root = createSampleTree();

    // Get the top view of the binary tree
    vector<int> topView = getTopView(root);

    // Print the top view elements
    cout << "Top View of the Binary Tree: ";
    for (int val : topView)
    {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the dynamically allocated memory
    // This step is important to avoid memory leaks but can be skipped for simplicity in this example.

    return 0;
}
