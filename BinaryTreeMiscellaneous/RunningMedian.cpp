//Brute force T.C=>O(n^2) and S.C=>O(n)
void findMedian(int *arr, int n)
{
    vector<int> vec;
    for(int i=0; i<n; i++){
        vec.push_back(arr[i]);
        int hole=i;
        //insertion sort to sort online
        while(hole>0 && vec[hole]>arr[i]){
            vec[hole] = vec[hole-1];
            hole--;
        }
        vec[hole] = arr[i];
        if(vec.size()%2)
            cout<<vec[vec.size()/2]<<" ";
        else
            cout<<(vec[vec.size()/2]+vec[(vec.size()/2)-1])/2<<" ";
    }
    cout<<endl;
}
//Optimal O(nlogn)
void findMedian(int *arr, int n)
{
    vector<int> vec;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<n; i++){
        //selectively insert
        if(maxHeap.empty() || arr[i]<maxHeap.top()){
            maxHeap.push(arr[i]);
        }
        else{
            minHeap.push(arr[i]);
        }
        //balance the heaps so that maxHeap.size-minHeap.size <=1
        if(abs(maxHeap.size()-minHeap.size())>1){
            if(maxHeap.size()>minHeap.size()){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }

        int minS = minHeap.size();//size of min Heap
        int maxS = maxHeap.size();//size of max Heap
        //if no. elements is odd output the top from larger heap
        if((minS+maxS)%2){
            if(minS<maxS)
                cout<<maxHeap.top()<<" ";
            else
                cout<<minHeap.top()<<" ";
        }
        //else output the average of tops of both heaps
        else{
            cout<<(minHeap.top()+maxHeap.top())/2<<" ";
        }
    }
    cout<<endl;
}