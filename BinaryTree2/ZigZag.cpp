#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BinaryTreeNode class definition (for code studio function)
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

// Function for code studio
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> res;
    if (!root)
        return res;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        if (cnt % 2)
            res.resize(res.size() + sz);
        for (int i = 0; i < sz; i++)
        {
            BinaryTreeNode<int> *curr = q.front();
            q.pop();
            if (cnt % 2)
                res[res.size() - i - 1] = curr->data;
            else
                res.push_back(curr->data);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cnt++;
    }
    return res;
}

// TreeNode class definition (for leetcode function)
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function for leetcode
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (!root)
        return result;

    queue<TreeNode *> q;
    q.push(root);
    bool flag = true;

    while (!q.empty())
    {
        int qsize = q.size();
        vector<int> level(qsize);
        for (int i = 0; i < qsize; i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            if (flag)
                level[i] = cur->val;
            else
                level[qsize - i - 1] = cur->val;
            if (cur && cur->left)
                q.push(cur->left);
            if (cur && cur->right)
                q.push(cur->right);
        }
        result.emplace_back(level);
        flag = flag ? false : true;
    }
    return result;
}

int main()
{
    // Test for code studio function
    BinaryTreeNode<int> *root1 = new BinaryTreeNode<int>(1);
    root1->left = new BinaryTreeNode<int>(2);
    root1->right = new BinaryTreeNode<int>(3);
    root1->left->left = new BinaryTreeNode<int>(4);
    root1->left->right = new BinaryTreeNode<int>(5);

    vector<int> res1 = zigZagTraversal(root1);
    cout << "Code Studio Function Output:" << endl;
    for (int val : res1)
    {
        cout << val << " ";
    }
    cout << endl;

    // Test for leetcode function
    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);

    vector<vector<int>> res2 = zigzagLevelOrder(root2);
    cout << "Leetcode Function Output:" << endl;
    for (const vector<int> &level : res2)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
