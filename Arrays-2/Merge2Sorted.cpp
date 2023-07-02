#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// With extra space O(m) and T.C = O(m+n)
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    vector<int> copy = arr1;
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (copy[i] <= arr2[j]) {
            arr1[k] = copy[i];
            i++;
        } else {
            arr1[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < m) {
        arr1[k++] = copy[i++];
    }
    while (j < n) {
        arr1[k++] = arr2[j++];
    }
    return arr1;
}

// Without extra space T.C = O(nlogn)
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    arr1.resize(m);
    int i = m - 1, j = 0, k = 0;
    while (i >= 0 && j < n) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
        } else {
            break;
        }
        i--;
        j++;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    arr1.resize(m + n, 0);
    for (int i = m; i < m + n; i++) {
        arr1[i] = arr2[k++];
    }
    return arr1;
}

int main() {
    int m, n;
    cout << "Enter the size of the first array: ";
    cin >> m;
    cout << "Enter the size of the second array: ";
    cin >> n;

    vector<int> arr1(m);
    vector<int> arr2(n);

    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    vector<int> mergedArray1 = ninjaAndSortedArrays(arr1, arr2, m, n);
    vector<int> mergedArray2 = ninjaAndSortedArrays(arr1, arr2, m, n);

    cout << "Merged array (with extra space): ";
    for (int i = 0; i < m + n; i++) {
        cout << mergedArray1[i] << " ";
    }
    cout << endl;

    cout << "Merged array (without extra space): ";
    for (int i = 0; i < m + n; i++) {
        cout << mergedArray2[i] << " ";
    }
    cout << endl;

    return 0;
}
