//O(n^2)
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    while(firstHead){
        Node* tmp = secondHead;
        while(tmp){
            if(firstHead==tmp)
                return tmp;
            tmp = tmp->next;
        }
        firstHead = firstHead->next;
    }
    return NULL;
}
//O(2*n)
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node* p1 = firstHead, *p2 = secondHead;
    int i=0, n=10e4;
    while(p1!=p2 && i<2){
        p1 = p1? p1->next: secondHead;
        p2 = p2? p2->next: firstHead;
        if(!p1) i++;
    }
    return p1;
}