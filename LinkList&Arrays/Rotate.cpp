int length(Node* head){
     int i=0;
     while(head) {
          head = head->next;
          i++;
     }
     return i;
}
Node *rotate(Node *head, int k) {
     k = k%length(head);
     if(!head || !head->next || k==0) return head;
     Node* fast=head, *slow = head;
     while(k--){
          fast = fast->next;
     }
     while(fast->next){
          slow = slow->next;
          fast = fast->next;
     }
     Node* fwd = slow->next;
     slow->next = NULL;
     fast->next = head;
     return fwd;
}