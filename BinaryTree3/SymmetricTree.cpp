bool testSymmetric(BinaryTreeNode<int>* l, BinaryTreeNode<int>* r){
        if(l==NULL && r==NULL)
            return true;
        else if(l==NULL || r==NULL)
            return false;
        if(l->data!=r->data)
            return false;
        return testSymmetric(l->left, r->right) && testSymmetric(l->right, r->left);
    }

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root==NULL)
            return true;
        return testSymmetric(root->left, root->right);   
}