#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Approach 1: Previous approach (did not work)
void inorderLeft(BinaryTreeNode<int> *root, stack<int> &stk)
{
    if (!root)
        return;
    inorderLeft(root->right, stk);
    stk.push(root->data);
    inorderLeft(root->left, stk);
}

void inorderRight(BinaryTreeNode<int> *root, stack<int> &stk)
{
    if (!root)
        return;
    inorderRight(root->left, stk);
    stk.push(root->data);
    inorderRight(root->right, stk);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    stack<int> stk1, stk2;
    // for left subtree
    inorderLeft(root->left, stk1);
    // for right subtree
    stk2.push(root->data);
    inorderRight(root->right, stk2);
    //
    while (!stk1.empty() && !stk2.empty())
    {
        int sum = stk1.top() + stk2.top();
        if (sum < k)
            stk1.pop();
        else if (sum > k)
            stk2.pop();
        else if (sum == k)
            return true;
    }
    return false;
}

// Approach 2: Optimal solution using BSTIterator
class BSTIterator
{
    stack<BinaryTreeNode<int> *> stk;
    bool reverse = true;

public:
    BSTIterator(BinaryTreeNode<int> *root, bool isRev)
    {
        reverse = isRev;
        pushAll(root);
    }
    bool hasNext()
    {
        return !stk.empty();
    }
    int next()
    {
        BinaryTreeNode<int> *tmp = stk.top();
        stk.pop();
        if (!reverse)
            pushAll(tmp->right);
        else
            pushAll(tmp->left);
        return tmp->data;
    }

private:
    void pushAll(BinaryTreeNode<int> *node)
    {
        for (; node != NULL;)
        {
            stk.push(node);
            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }
};

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    if (!root)
        return false;
    BSTIterator l(root, false);
    BSTIterator r(root, true);

    int i = l.next();
    int j = r.next();
    while (i < j)
    {
        if (i + j == k)
            return true;
        else if (i + j < k)
            i = l.next();
        else
            j = r.next();
    }
    return false;
}

// Helper function to create a sample binary tree
BinaryTreeNode<int> *createSampleTree()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(15);
    root->left = new BinaryTreeNode<int>(10);
    root->right = new BinaryTreeNode<int>(20);
    root->left->left = new BinaryTreeNode<int>(5);
    root->left->right = new BinaryTreeNode<int>(12);
    root->right->left = new BinaryTreeNode<int>(17);
    root->right->right = new BinaryTreeNode<int>(25);
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = createSampleTree();

    // Testing Approach 1
    cout << "Using Approach 1:\n";
    int k1 = 27;
    bool result1 = pairSumBst(root, k1);
    cout << "Pair with sum " << k1 << " is " << (result1 ? "found" : "not found") << endl;

    // Testing Approach 2
    cout << "\nUsing Approach 2:\n";
    int k2 = 37;
    bool result2 = pairSumBst(root, k2);
    cout << "Pair with sum " << k2 << " is " << (result2 ? "found" : "not found") << endl;

    return 0;
}
