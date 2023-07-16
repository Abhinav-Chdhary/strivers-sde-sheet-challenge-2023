//Iterative
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(root1==NULL && root2==NULL) return true;
    if(root1==NULL || root2==NULL) return false;
    queue<BinaryTreeNode<int>*> q1, q2;
    q1.push(root1);
    q2.push(root2);
    while(!q1.empty() && !q2.empty()){
        auto it1 = q1.front();
        auto it2 = q2.front();
        q1.pop(); q2.pop();

        if(it1->data!=it2->data) return false;

        // Check left children
        if (it1->left && it2->left) {
            q1.push(it1->left);
            q2.push(it2->left);
        } else if (it1->left || it2->left) {
            // One has a left child and the other doesn't
            return false;
        }

        // Check right children
        if (it1->right && it2->right) {
            q1.push(it1->right);
            q2.push(it2->right);
        } else if (it1->right || it2->right) {
            // One has a right child and the other doesn't
            return false;
        }
    }
    return q1.empty() && q2.empty();
}
//Recursive
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
     if (root1 == NULL && root2 == NULL)
    return true;
  else if (root1 == NULL || root2 == NULL)
    return false;

  return ((root1 -> data == root2 -> data) && identicalTrees(root1 -> left, root2-> left) && identicalTrees(root1 -> right, root2 -> right));

}