#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;

vector<int> nextPermutation(vector<int> &per, int n)
{
    int ind = -1;
    //find dip point
    for(int i=n-2; i>=0; i--){
        if(per[i]<per[i+1]){
            ind = i;
            break;
        }
    }
    //if no dip point found
    if(ind==-1){
        reverse(per.begin(), per.end());
        return per;
    }
    //swap the next greater element we scan
    for(int i=n-1; i>=ind; i--){
        if(per[i]>per[ind]){
            swap(per[i], per[ind]);
            break;
        }
    }
    //reverse the rest of the portion
    reverse(per.begin()+ind+1, per.end());
    return per;
}

int main() {
    // Example usage
    vector<int> permutation = {1, 2, 3};
    int size = permutation.size();

    // Compute the next permutation
    vector<int> nextPerm = nextPermutation(permutation, size);

    // Print the result
    cout << "Next permutation: ";
    for (int i = 0; i < size; i++) {
        cout << nextPerm[i] << " ";
    }
    cout << endl;

    return 0;
}