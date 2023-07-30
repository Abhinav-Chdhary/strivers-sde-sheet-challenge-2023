#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// BinaryTreeNode structure
template <typename T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to create a new node
template <typename T>
BinaryTreeNode<T> *createNode(T value)
{
    return new BinaryTreeNode<T>(value);
}

// Function to insert nodes into the binary tree
template <typename T>
BinaryTreeNode<T> *insertNode(BinaryTreeNode<T> *root, T value)
{
    if (root == nullptr)
        return createNode(value);
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    return root;
}

// Function to perform the bottom view of the binary tree
template <typename T>
vector<int> bottomView(BinaryTreeNode<T> *root)
{
    if (!root)
        return {};
    map<int, T> lineToNode;
    queue<pair<BinaryTreeNode<T> *, int>> q;
    q.push({root, 0});
    vector<int> ans;

    while (!q.empty())
    {
        BinaryTreeNode<T> *curr = q.front().first;
        int line = q.front().second;
        lineToNode[line] = curr->data;
        q.pop();
        if (curr->left)
            q.push({curr->left, line - 1});
        if (curr->right)
            q.push({curr->right, line + 1});
    }

    for (const auto &item : lineToNode)
    {
        ans.push_back(item.second);
    }
    return ans;
}

// Function to perform in-order traversal of the binary tree
template <typename T>
void inOrderTraversal(BinaryTreeNode<T> *root)
{
    if (root)
    {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main()
{
    // Create a binary tree
    BinaryTreeNode<int> *root = nullptr;
    root = insertNode(root, 20);
    insertNode(root, 10);
    insertNode(root, 30);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 25);
    insertNode(root, 35);

    cout << "In-order traversal of the binary tree: ";
    inOrderTraversal(root);
    cout << endl;

    // Perform bottom view of the binary tree
    vector<int> bottomViewResult = bottomView(root);

    cout << "Bottom view of the binary tree: ";
    for (int nodeValue : bottomViewResult)
    {
        cout << nodeValue << " ";
    }
    cout << endl;

    return 0;
}
