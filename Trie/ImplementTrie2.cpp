#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    int freqCount = 0;
    int endsCount = 0;
    bool hasKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void increaseEnd(){
        endsCount++;
    }
    void increaseFreq(){
        freqCount++;
    }
    void deleteEnd(){
        endsCount--;
    }
    void deleteFreq(){
        freqCount--;
    }
    int getEndWith(){
        return endsCount;
    }
    int getFreqCount(){
        return freqCount;
    }
};
class Trie{
    Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->hasKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increaseFreq();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node->hasKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }
        return node->getEndWith();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node->hasKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }
        return node->getFreqCount();
    }

    void erase(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
          if (node->hasKey(word[i])) {
            node = node->get(word[i]);
            node->deleteFreq();
          } else
            return;
        }
        return node->deleteEnd();
    }
};
