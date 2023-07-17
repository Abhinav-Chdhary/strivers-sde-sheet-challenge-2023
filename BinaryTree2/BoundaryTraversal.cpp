#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* node){
    return node->left==NULL && node->right==NULL;
}
void leftBoundary(TreeNode<int>* root, vector<int> &res){
    root=root->left;
    while(root){
        if(!isLeaf(root))
            res.push_back(root->data);
        if(root->left)
            root = root->left;
        else
            root = root->right;
    }
}
void bottomBoundary(TreeNode<int>* root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) bottomBoundary(root->left, res);
    if(root->right) bottomBoundary(root->right, res);
}
void rightBoundary(TreeNode<int>* root, vector<int> &res){
    root = root->right;
    stack<int> stk;
    while(root){
        if(!isLeaf(root))
            stk.push(root->data);
        if(root->right) root=root->right;
        else root=root->left;
    }
    while(!stk.empty()){
        res.push_back(stk.top());
        stk.pop();
    }
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root))
        res.push_back(root->data);
    leftBoundary(root, res);
    bottomBoundary(root, res);
    rightBoundary(root, res);
    return res;
}