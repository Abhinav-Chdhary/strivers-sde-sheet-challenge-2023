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