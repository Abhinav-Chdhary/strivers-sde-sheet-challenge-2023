LinkedListNode<int> *reverse(LinkedListNode<int> *head){
    if(!head || !head->next){
        return head;
    }
    LinkedListNode<int> *node = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return node;
}
bool isPalindrome(LinkedListNode<int> *head) {
    if(!head || !head->next){
        return true;
    }
    LinkedListNode<int> *fast, *slow;
    fast = slow = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    LinkedListNode<int> *slow1 = head;
    LinkedListNode<int> *slow2 = reverse(slow->next);
    while(slow1 && slow2){
        if(slow2->data!=slow1->data)
            return false;
        slow2=slow2->next;
        slow1=slow1->next;
    }
    return true;
}