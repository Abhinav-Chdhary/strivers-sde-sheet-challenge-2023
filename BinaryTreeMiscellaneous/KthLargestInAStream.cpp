#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Kthlargest
{
    int sz;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    Kthlargest(int k, vector<int> &arr)
    {
        sz = k;
        for (int x : arr)
            pq.push(x);
    }

    void add(int num)
    {
        pq.push(num);
    }

    int getKthLargest()
    {
        while (pq.size() > sz)
            pq.pop();
        return pq.top();
    }
};

int main()
{
    vector<int> arr = {3, 1, 6, 4, 2, 8};
    int k = 3;

    Kthlargest kthLargest(k, arr);

    cout << "Initial Kth largest: " << kthLargest.getKthLargest() << endl;

    int numToAdd = 5;
    kthLargest.add(numToAdd);
    cout << "Kth largest after adding " << numToAdd << ": " << kthLargest.getKthLargest() << endl;

    numToAdd = 7;
    kthLargest.add(numToAdd);
    cout << "Kth largest after adding " << numToAdd << ": " << kthLargest.getKthLargest() << endl;

    return 0;
}
