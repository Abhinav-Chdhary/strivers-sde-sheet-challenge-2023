bool traverse(TreeNode<int> *root, int target, vector<int> &ans){
	if(!root) return false;
	ans.push_back(root->data);
	if(root->data==target) return true;
	if(traverse(root->left, target, ans)||traverse(root->right, target, ans))
		return true;
	else
		ans.pop_back();
	return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
	traverse(root, x, ans);
	return ans;
}