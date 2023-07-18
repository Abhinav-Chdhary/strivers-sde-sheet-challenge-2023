TreeNode<int>* treeCreator(vector<int> &preorder, int &index, int key, int min, int max){
    if(index>=preorder.size()){
        return NULL;
    }
    TreeNode<int>* node = NULL;
    int sz = preorder.size();
    if(key>min && key<max){
        node = new TreeNode<int>(key);
        index++;
        if(index<sz)
            node->left = treeCreator(preorder, index, preorder[index], min, key);
        if(index<sz)
            node->right = treeCreator(preorder, index, preorder[index], key, max);
    }
    return node;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int ind = 0;
    return treeCreator(preOrder, ind, preOrder[0], INT_MIN, INT_MAX);
}