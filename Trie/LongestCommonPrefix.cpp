#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    bool flag = false;
    bool hasKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie {
    Node* root;
public:

    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->hasKey(word[i])){
                node->put(word[i], new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
			node = node->get(word[i]);
            if(!node->isEnd()) return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    Trie* trie = new Trie();
    for(int i=0; i<n; i++){
        trie->insert(a[i]);
    }
    string ans="";
    for(auto s: a){
        if(trie->search(s)){
            if(s.size()>ans.size())
                ans = s;
            else if((s.size()==ans.size() && s<ans))
                ans = s;
        }
    }
    if(ans.size()==0) return "None";
    return ans;
}