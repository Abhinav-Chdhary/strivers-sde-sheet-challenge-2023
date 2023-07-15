class Kthlargest {
    int sz;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    Kthlargest(int k, vector<int> &arr) {
        sz = k;
       for(int x: arr) pq.push(x);
    }

    void add(int num) {
        pq.push(num);
    }

    int getKthLargest() {
       while(pq.size()>sz) pq.pop();
       return pq.top();
    }

};