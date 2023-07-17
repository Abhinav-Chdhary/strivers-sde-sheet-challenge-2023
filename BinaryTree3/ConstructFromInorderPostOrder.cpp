TreeNode<int>* helper(vector<int>& inorder, int x, int y, vector<int>& postorder, int a, int b){
        if(x>y || a>b)  return NULL;
        TreeNode<int>* node = new TreeNode<int>(postorder[b]);
        //st means start_index
        int st=x;
        while(inorder[st]!=node->data)  st++;
        node->left = helper(inorder, x, st-1, postorder, a, a+st-x-1);
        node->right = helper(inorder, st+1, y, postorder, a+st-x, b-1);
        return node;
    }
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	return helper(inOrder, 0, inOrder.size()-1, postOrder, 0, postOrder.size()-1);
}