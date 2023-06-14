Node *reverse(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *prev = NULL, *curr = head;
    while (curr)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    Node *res = new Node(0);
    Node *tmp = res;
    int i = 0;
    while (i < n && head)
    {
        int sz = b[i];
        if (sz > 1)
        {
            Node *cur = head, *strt = head;
            while (--sz > 0 && cur->next)
            {
                cur = cur->next;
            }
            head = cur->next;
            cur->next = NULL;
            cur = reverse(strt);
            res->next = cur;
            while (res->next)
                res = res->next;
        }
        else if (sz == 1)
        {
            res->next = head;
            res = res->next;
            head = head->next;
        }
        i++;
    }
    if (head)
        res->next = head;
    return tmp->next;
}