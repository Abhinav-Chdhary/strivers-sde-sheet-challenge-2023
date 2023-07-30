#include <iostream>
#include <stack>

template <typename T>
struct TreeNode
{
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}
};

// Recursive version
TreeNode<int> *prevs = NULL;

void flattenTree(TreeNode<int> *root)
{
    if (!root)
        return;
    flattenTree(root->right);
    flattenTree(root->left);
    root->right = prevs;
    root->left = NULL;
    prevs = root;
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    flattenTree(root);
    prevs = NULL;
    return root;
}

// Iterative version
TreeNode<int> *flattenBinaryTreeIterative(TreeNode<int> *root)
{
    if (!root)
        return root;
    std::stack<TreeNode<int> *> stk;
    stk.push(root);
    while (!stk.empty())
    {
        TreeNode<int> *cur = stk.top();
        stk.pop();
        if (cur->right)
            stk.push(cur->right);
        if (cur->left)
            stk.push(cur->left);
        if (!stk.empty())
            cur->right = stk.top();
        cur->left = NULL;
    }
    return root;
}

// Helper function to print the flattened tree
void printFlattenedTree(TreeNode<int> *node)
{
    while (node != NULL)
    {
        std::cout << node->val << " ";
        node = node->right;
    }
    std::cout << std::endl;
}

int main()
{
    // Create a sample binary tree
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(5);
    root->left->left = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(4);
    root->right->right = new TreeNode<int>(6);

    std::cout << "Original tree: ";
    printFlattenedTree(root);

    // Flatten using recursive version
    TreeNode<int> *recursiveRoot = flattenBinaryTree(root);
    std::cout << "Flattened (Recursive): ";
    printFlattenedTree(recursiveRoot);

    // Create a new tree for the iterative version
    TreeNode<int> *root2 = new TreeNode<int>(1);
    root2->left = new TreeNode<int>(2);
    root2->right = new TreeNode<int>(5);
    root2->left->left = new TreeNode<int>(3);
    root2->left->right = new TreeNode<int>(4);
    root2->right->right = new TreeNode<int>(6);

    // Flatten using iterative version
    TreeNode<int> *iterativeRoot = flattenBinaryTreeIterative(root2);
    std::cout << "Flattened (Iterative): ";
    printFlattenedTree(iterativeRoot);

    return 0;
}
