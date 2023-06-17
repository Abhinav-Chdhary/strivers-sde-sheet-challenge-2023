class Stack {
	// Define the data members.
    queue<int> q;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }

    void push(int x) {
        q.push(x);
        int s = q.size();
        while(--s){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(q.empty()) return -1;
        int x = q.front(); q.pop();
        return x;
    }

    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
};