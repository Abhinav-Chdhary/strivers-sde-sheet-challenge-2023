#include <iostream>
#include <queue>

template <typename T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *next; // Pointer to the next node in the same level
    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr), next(nullptr) {}
};

void connectNodes(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    std::queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            BinaryTreeNode<int> *curr = q.front();
            q.pop();
            if (sz)
                curr->next = q.front();
            else
                curr->next = NULL;
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}

// Helper function to print the connected nodes (for demonstration purposes)
void printConnectedNodes(BinaryTreeNode<int> *root)
{
    while (root)
    {
        BinaryTreeNode<int> *current = root;
        while (current)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
        root = root->left;
    }
}

int main()
{
    // Create a sample binary tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);

    // Connect nodes at the same level
    connectNodes(root);

    // Print the connected nodes (Level order traversal with next pointers)
    std::cout << "Connected Nodes at the same level:\n";
    printConnectedNodes(root);

    // Clean up the allocated memory (optional in this case)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
