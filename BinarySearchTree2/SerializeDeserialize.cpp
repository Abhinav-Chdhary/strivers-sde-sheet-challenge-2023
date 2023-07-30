#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// TreeNode class definition
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T value) : data(value), left(NULL), right(NULL) {}
};

// Serialization function
string serializeTree(TreeNode<int> *root)
{
    if (!root)
        return "";
    string res = "";
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *curr = q.front();
        q.pop();
        if (curr)
        {
            res += to_string(curr->data) + ",";
        }
        else
        {
            res += "-1,";
        }
        if (curr)
        {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return res;
}

// Deserialization function
TreeNode<int> *deserializeTree(string &serialized)
{
    if (serialized == "")
        return NULL;
    vector<int> serial;
    string wrd = "";
    for (int i = 0; i < serialized.length(); i++)
    {
        if (serialized[i] == ',')
        {
            serial.push_back(stoi(wrd));
            wrd = "";
        }
        else
        {
            wrd += serialized[i];
        }
    }
    queue<TreeNode<int> *> levels;
    int i = 0;
    TreeNode<int> *root = new TreeNode<int>(serial[i++]);
    levels.push(root);
    while (!levels.empty())
    {
        TreeNode<int> *node = levels.front();
        levels.pop();
        // for left
        if (serial[i] == -1)
            node->left = NULL;
        else
        {
            node->left = new TreeNode<int>(serial[i]);
            levels.push(node->left);
        }
        i++;
        // for right
        if (serial[i] == -1)
            node->right = NULL;
        else
        {
            node->right = new TreeNode<int>(serial[i]);
            levels.push(node->right);
        }
        i++;
    }
    return root;
}

int main()
{
    // Driver code to demonstrate serialization and deserialization
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    // Serialize the tree
    string serializedTree = serializeTree(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    // Deserialize the tree
    TreeNode<int> *deserializedRoot = deserializeTree(serializedTree);

    // Print the deserialized tree (in serialized form again)
    string deserializedTree = serializeTree(deserializedRoot);
    cout << "Deserialized Tree: " << deserializedTree << endl;

    // Clean up the memory (optional, but recommended)
    // TODO: Implement a function to delete the tree nodes to avoid memory leaks.

    return 0;
}
