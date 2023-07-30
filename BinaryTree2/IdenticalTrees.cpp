#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node
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
        this->left = NULL;
        this->right = NULL;
    }
};

// Iterative approach
bool identicalTreesIterative(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;

    queue<BinaryTreeNode<int> *> q1, q2;
    q1.push(root1);
    q2.push(root2);

    while (!q1.empty() && !q2.empty())
    {
        auto it1 = q1.front();
        auto it2 = q2.front();
        q1.pop();
        q2.pop();

        if (it1->data != it2->data)
            return false;

        // Check left children
        if (it1->left && it2->left)
        {
            q1.push(it1->left);
            q2.push(it2->left);
        }
        else if (it1->left || it2->left)
        {
            // One has a left child and the other doesn't
            return false;
        }

        // Check right children
        if (it1->right && it2->right)
        {
            q1.push(it1->right);
            q2.push(it2->right);
        }
        else if (it1->right || it2->right)
        {
            // One has a right child and the other doesn't
            return false;
        }
    }

    return q1.empty() && q2.empty();
}

// Recursive approach
bool identicalTreesRecursive(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    else if (root1 == NULL || root2 == NULL)
        return false;

    return ((root1->data == root2->data) && identicalTreesRecursive(root1->left, root2->left) && identicalTreesRecursive(root1->right, root2->right));
}

int main()
{
    // Creating binary trees
    BinaryTreeNode<int> *root1 = new BinaryTreeNode<int>(1);
    root1->left = new BinaryTreeNode<int>(2);
    root1->right = new BinaryTreeNode<int>(3);
    root1->left->left = new BinaryTreeNode<int>(4);
    root1->left->right = new BinaryTreeNode<int>(5);

    BinaryTreeNode<int> *root2 = new BinaryTreeNode<int>(1);
    root2->left = new BinaryTreeNode<int>(2);
    root2->right = new BinaryTreeNode<int>(3);
    root2->left->left = new BinaryTreeNode<int>(4);
    root2->left->right = new BinaryTreeNode<int>(5);

    // Test the iterative approach
    cout << "Iterative Approach: ";
    if (identicalTreesIterative(root1, root2))
        cout << "The trees are identical." << endl;
    else
        cout << "The trees are not identical." << endl;

    // Test the recursive approach
    cout << "Recursive Approach: ";
    if (identicalTreesRecursive(root1, root2))
        cout << "The trees are identical." << endl;
    else
        cout << "The trees are not identical." << endl;

    return 0;
}
