Node* merger(Node* h1, Node* h2){
	Node* tmp, *res;
	tmp = res = new Node(0);
	while(h1 && h2){
        if (h1->data <= h2->data) {
        	tmp->child = h1;
			h1 = h1->child;
        }
		else{
			tmp->child = h2;
			h2 = h2->child;
		}
		tmp = tmp->child;
    }
	if(h1){
		tmp->child = h1;
	}
	if(h2){
		tmp->child = h2;
	}
	return res->child;
}
Node* flattenLinkedList(Node* head) 
{
	if(!head||!head->next) return head;
	
	Node* tmp = flattenLinkedList(head->next);
	head->next = NULL;
	head = merger(head, tmp);
	return head;
}