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