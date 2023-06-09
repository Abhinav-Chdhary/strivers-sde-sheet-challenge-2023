//iterative solution
Node *reverseLinkedList(Node *head) 
{
    Node *prev = NULL, *curr=head;
    while(curr){
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
//recursive
Node *reverseLinkedList(Node *head) 
{
    if(!head||!head->next)
        return head;

    Node *curr = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return curr;
}