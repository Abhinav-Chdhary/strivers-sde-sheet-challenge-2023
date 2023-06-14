Node *firstNode(Node *head)
{
    Node* slow, *fast, *tmp;
    fast = slow = head;
    tmp = NULL;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow){
            tmp = head;
            while(tmp!=fast){
                tmp = tmp->next;
                fast = fast->next;
            }
            return tmp;
        }
    }
    return tmp;
}