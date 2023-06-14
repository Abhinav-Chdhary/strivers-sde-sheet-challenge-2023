//Brute force find length and then delete from last O(2*n)
//Optimal O(n)
Node* removeKthNode(Node* head, int K)
{
    Node* start = new Node(0);
        Node* slow = start;
        Node* fast = start;
        slow -> next = head;
        for(int i = 1; i <= K + 1; i++)   {
            fast = fast -> next;
        }
        while (fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        slow -> next = slow -> next -> next;
        return start -> next;
}