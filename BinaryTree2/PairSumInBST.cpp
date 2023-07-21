// This did not work but I spent a lot of time making it work so..
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
    // for left ppl
    inorderLeft(root->left, stk1);
    // for right ppl
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
// Optimal solution
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