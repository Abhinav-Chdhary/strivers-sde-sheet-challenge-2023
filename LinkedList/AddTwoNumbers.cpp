//Iterative soltion
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp = new ListNode(0);
        ListNode *res = temp;
        int c=0;
        while(c||l1||l2){
            c+= (l1?l1->val:0) + (l2?l2->val:0);
            ListNode* p = new ListNode(c%10);
            res->next = p;
            res = p;
            c/=10;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return temp->next;
    }
//Recursive
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2){
            return NULL;
        }
        int c = (l1? l1->val: 0) + (l2? l2->val:0);
        ListNode* result = new ListNode(c%10);
        ListNode* next = (l1? l1->next: NULL);
        c/=10;
        if(next) next->val+=c;
        else if(c) next=new ListNode(c);
        result->next = addTwoNumbers(next, l2? l2->next: NULL);
        return result;
    }