//code studio
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> res; 
    if(!root) return res;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    int cnt=0;
    while(!q.empty()){
        int sz=q.size();
        if(cnt%2)
            res.resize(res.size()+sz);
        for(int i=0; i<sz; i++){
            BinaryTreeNode<int>* curr = q.front();
            q.pop();
            if(cnt%2)
                res[res.size()-i-1] = curr->data;
            else
                res.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        cnt++;
    }
    return res;
}
//leetcode
 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;

        while(!q.empty()){
            int qsize = q.size();
            vector<int> level(qsize);
            for(int i=0; i<qsize; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(flag) level [i] = cur->val;
                else    level[qsize-i-1] = cur->val;
                if(cur && cur->left)   q.push(cur->left);
                if(cur && cur->right)  q.push(cur->right);
            }
            result.emplace_back(level);
            flag = flag? false: true;
        }
        return result;
    }