#include <iostream>

using namespace std;

//Brute: Sort using std algos => O(nlogn)
//Better: count sort => O(2*n)
//Optimal: Dutch flag algorithm => O(n)
void sort012(int *arr, int n)
{
   //keep the 3 colors of dutch flag from mingling
   int l, m, h;
   l=m=0; h = n-1;
   while(m<=h){
      //if current is 0 put it in the '0' portion of the array
      if(arr[m]==0){
         swap(arr[m], arr[l]);
         l++; m++;
      }
      //if current is 2 put it in the '2' portion of the array
      else if(arr[m]==2){
         swap(arr[m], arr[h]);
         h--;
      }
      //if current is 1 just increment
      else{
         m++;
      }
   }
}
int main() {
    // Example usage
    int arr[] = {2, 0, 1, 2, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Perform sorting
    sort012(arr, size);

    // Print the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}