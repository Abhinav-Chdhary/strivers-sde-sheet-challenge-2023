TreeNode<int>* building(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int> &um){
        if(preStart>preEnd || inStart>inEnd)
            return NULL;
        TreeNode<int>* node = new TreeNode<int>(preorder[preStart]);
        int inRoot = um[node->data];
        int numsLeft = inRoot - inStart;
        node->left = building(preorder, inorder, preStart+1, preStart+numsLeft, inStart, inRoot-1, um);
        node->right = building(preorder, inorder, preStart+numsLeft+1, preEnd, inRoot+1, inEnd, um);
        return node;
    }
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	unordered_map<int, int> um;
        for(int i=0; i<inorder.size(); i++){
            um[inorder[i]] = i;
        }
        return building(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, um);
}