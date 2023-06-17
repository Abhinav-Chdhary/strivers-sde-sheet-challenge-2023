class Queue {
    stack<int> inp, out;
    
    public:
    Queue() {}

    void enQueue(int val) {
        inp.push(val);
    }

    int deQueue() {
        if(isEmpty()) return -1;
        peek();
        int x = out.top();
        out.pop();
        return x;
    }

    int peek() {
        if(isEmpty()) return -1;
        if(out.empty()){
            while(!inp.empty()){
                out.push(inp.top());
                inp.pop();
            }
        }
        return out.top();
    }

    bool isEmpty() {
        return inp.empty() && out.empty();
    }
};