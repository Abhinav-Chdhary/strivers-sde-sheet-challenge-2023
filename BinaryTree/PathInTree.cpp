#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct TreeNode
{
	T data;
	TreeNode *left;
	TreeNode *right;
	TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

bool traverse(TreeNode<int> *root, int target, vector<int> &ans)
{
	if (!root)
		return false;
	ans.push_back(root->data);
	if (root->data == target)
		return true;
	if (traverse(root->left, target, ans) || traverse(root->right, target, ans))
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

int main()
{
	// Sample tree creation
	TreeNode<int> *root = new TreeNode<int>(1);
	root->left = new TreeNode<int>(2);
	root->right = new TreeNode<int>(3);
	root->left->left = new TreeNode<int>(4);
	root->left->right = new TreeNode<int>(5);
	root->right->left = new TreeNode<int>(6);
	root->right->right = new TreeNode<int>(7);

	int targetNode = 5;
	vector<int> result = pathInATree(root, targetNode);

	cout << "Path to node " << targetNode << ": ";
	for (int val : result)
	{
		cout << val << " ";
	}
	cout << endl;

	// Memory cleanup (optional, depending on your use case)
	delete root->left->right;
	delete root->left->left;
	delete root->left;
	delete root->right->right;
	delete root->right->left;
	delete root->right;
	delete root;

	return 0;
}
