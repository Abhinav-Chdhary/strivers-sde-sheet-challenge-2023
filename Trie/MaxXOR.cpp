//Brute force O(n^2)
int maximumXor(vector<int> A)
{
    if(A.size()==1) return 0;
    //sort(A.begin(), A.end());
    int i=0, n=A.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ans = max(A[i]^A[j], ans);
        }
    }
    return ans;
}
//Optimal using trie
class Node{
    public:
    Node *one, *zero;
};
class Trie{
    Node* root = new Node();
    public:
    void insert(int num){
        Node* curr = root;
        int bitInd = 30;
        while(bitInd>=0){
            int mask = 1<<bitInd;
            if(num&mask){
                if(!curr->one)
                    curr->one = new Node();
                curr = curr->one;
            }
            else{
                if(!curr->zero)
                    curr->zero = new Node();
                curr = curr->zero;
            }
            bitInd--;
        }
    }
    int query(int find){
        Node* curr = root;
        int ans = 0, bitInd = 30;
        while(bitInd>=0){
            int mask = 1<<bitInd;
            if(find&mask){
                if(curr->one){
                    curr = curr->one;
                    ans |= mask;
                }
                else if(curr->zero) curr = curr->zero;
            }
            else{
                if(curr->zero)
                    curr = curr->zero;
                else if(curr->one){ 
                    curr = curr->one;
                    ans |= mask;
                }
            }
            bitInd--;
        }
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *trie = new Trie();
        int ans = 0, n= nums.size();
        for(int i=0; i<n; i++){
            trie->insert(nums[i]);
        }
        for(int i=0; i<n; i++){
            int find = INT_MAX ^ nums[i];
            int b = trie->query(find);
            ans = max(ans, nums[i]^b);
        }
        return ans;
    }
};
