#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void findMedian(int *arr, int n)
{
    vector<int> vec;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        // selectively insert
        if (maxHeap.empty() || arr[i] < maxHeap.top())
        {
            maxHeap.push(arr[i]);
        }
        else
        {
            minHeap.push(arr[i]);
        }
        // balance the heaps so that maxHeap.size-minHeap.size <=1
        if (abs(maxHeap.size() - minHeap.size()) > 1)
        {
            if (maxHeap.size() > minHeap.size())
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }

        int minS = minHeap.size(); // size of min Heap
        int maxS = maxHeap.size(); // size of max Heap
        // if no. elements is odd output the top from larger heap
        if ((minS + maxS) % 2)
        {
            if (minS < maxS)
                cout << maxHeap.top() << " ";
            else
                cout << minHeap.top() << " ";
        }
        // else output the average of tops of both heaps
        else
        {
            cout << (minHeap.top() + maxHeap.top()) / 2 << " ";
        }
    }
    cout << endl;
}

int main()
{
    int arr[] = {5, 15, 10, 20, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    findMedian(arr, n);

    return 0;
}
