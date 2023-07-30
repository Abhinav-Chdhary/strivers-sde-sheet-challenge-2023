#include <iostream>
#include <stack>

using namespace std;

// Define the TreeNode class
template <typename T>
struct TreeNode
{
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// Define the BSTiterator class
template <typename T>
class BSTiterator
{
private:
    stack<T> stk;

    void inorder(TreeNode<T> *root)
    {
        if (!root)
            return;
        inorder(root->right);
        stk.push(root->data);
        inorder(root->left);
    }

public:
    BSTiterator(TreeNode<T> *root)
    {
        inorder(root);
    }

    T next()
    {
        T val = stk.top();
        stk.pop();
        return val;
    }

    bool hasNext()
    {
        return !stk.empty();
    }
};

// Helper function to construct a binary search tree
TreeNode<int> *insert(TreeNode<int> *root, int val)
{
    if (!root)
        return new TreeNode<int>(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Helper function to create a sample binary search tree
TreeNode<int> *createBST()
{
    TreeNode<int> *root = nullptr;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    return root;
}

int main()
{
    TreeNode<int> *root = createBST();

    // Create a BSTiterator object
    BSTiterator<int> bstIterator(root);

    // Test the functionalities of the BSTiterator
    cout << "BST in ascending order: ";
    while (bstIterator.hasNext())
    {
        cout << bstIterator.next() << " ";
    }
    cout << endl;

    return 0;
}
