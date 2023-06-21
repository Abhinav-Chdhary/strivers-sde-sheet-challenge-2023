#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/
//Don't look at this code
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if(!head) return head;
    LinkedListNode<int>* myHead = new LinkedListNode<int>(head->data);
     LinkedListNode<int> *res = myHead, *copy = head;
    head = head->next;

    while(head){
        myHead->next = new LinkedListNode<int>(head->data);
        head = head->next;
        myHead = myHead->next;
    }
    head = copy;
    myHead = res;
    //totally wrong approach but somehow worked in Coding Ninjas
    //If I can access leetcode, I have no reason to code studio, it's a failed idea bro
    while(head){
        myHead->random = head->random;
        head = head->next;
        myHead = myHead->next;
    }
    return res;
}
//Brute Force Approach
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* myHead = head;
        unordered_map<Node*, Node*> um;
        while(myHead){
            um[myHead] = new Node(myHead->val);
            myHead = myHead->next;
        }
        myHead = head;
        while(myHead){
            um[myHead]->next = um[myHead->next];
            um[myHead]->random = um[myHead->random];
            myHead = myHead->next;
        }
        return um[head];
    }
};
