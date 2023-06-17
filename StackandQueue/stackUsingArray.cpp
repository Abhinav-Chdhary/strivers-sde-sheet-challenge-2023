class Stack {
    int *arr;
    int ind, n;
public:
    
    Stack(int capacity) {
        n = capacity;
        arr = new int[capacity];
        ind = -1;
    }

    void push(int num) {
        arr[++ind] = num;
    }

    int pop() {
        if(ind==-1) return -1;
        return arr[ind--];
    }
    
    int top() {
        if(ind==-1) return -1;
        return arr[ind];
    }
    
    int isEmpty() {
        return ind==-1;
    }
    
    int isFull() {
        return ind==n-1;
    }
    
};