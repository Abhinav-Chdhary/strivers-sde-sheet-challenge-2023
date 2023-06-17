class Queue {
    int *arr;
    int f, r;
public:
    Queue() {
        arr = new int[5001];
        f = r = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return f==-1 && r==-1;
    }

    void enqueue(int data) {
        arr[++r] = data;
        if(f==-1) f=0;
    }

    int dequeue() {
        if(f==-1) return -1;
        int res = arr[f++];
        if(f>r) r = f = -1;
        return res;
    }

    int front() {
        if(f==-1) return -1;
        return arr[f];
    }
};