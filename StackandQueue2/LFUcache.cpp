#include <bits/stdc++.h> 
struct Node{
    int key;
    int val;
    int cnt;
    Node* prev;
    Node* next;
    Node(int _key, int _value){
        key = _key;
        val = _value;
        cnt=1;
    }
};
struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node *node){
        Node* tmp = head->next;
        node->next = tmp;
        node->prev = head;
        tmp->prev = node;
        head->next = node;
        size++;
    }
    void removeNode(Node* delnode){
        Node* before = delnode->prev;
        Node* after = delnode->next;
        before->next = after;
        after->prev = before;
       // delete(delnode);
        size--;
    }

};

class LFUCache
{
    int leastFreq;
    int capacity;
    unordered_map<int, Node*> dictionary;
    unordered_map<int, List*> freqMap;
public:
    LFUCache(int capacity)
    {
        leastFreq = 0;
        this->capacity = capacity;
    }
    void updateFreqList(Node *node){
        dictionary.erase(node->key);
        freqMap[node->cnt]->removeNode(node);
        if(node->cnt==leastFreq && freqMap[node->cnt]->size==0){
            leastFreq++;
        }
        List* nextHigherFreqList = new List();
        if(freqMap.find(node->cnt+1)!=freqMap.end())
            nextHigherFreqList = freqMap[node->cnt+1];
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqMap[node->cnt] = nextHigherFreqList;
        dictionary[node->key] = node;
    }
    int get(int key)
    {
        if(dictionary.find(key)!=dictionary.end()){
            Node* node = dictionary[key];
            int value = node->val;
            updateFreqList(node);
            return value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(capacity==0) return;
        if(dictionary.find(key)!=dictionary.end()){
            dictionary[key]->val = value;
            updateFreqList(dictionary[key]);
        }
        else{
            if(dictionary.size()==capacity){
                List* list = freqMap[leastFreq];
                dictionary.erase(list->tail->prev->key);
                freqMap[leastFreq]->removeNode(list->tail->prev);
            }
            leastFreq = 1;
            List* listFreq = new List();
            if(freqMap.find(leastFreq) != freqMap.end()){
                listFreq = freqMap[leastFreq];
            }
            Node* node = new Node(key, value);
            listFreq->addFront(node);
            dictionary[key] = node;
            freqMap[leastFreq] = listFreq;
        }
    }
};
