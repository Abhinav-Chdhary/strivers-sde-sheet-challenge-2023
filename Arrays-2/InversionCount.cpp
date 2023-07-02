#include <iostream>
#include <vector>

using namespace std;

long long merger(long long nums[], int l, int mid, int r) {
    int i = l, j, k, m = (mid - l) + 1, n = r - mid;
    j = k = 0;
    vector<int> arr1(m, 0), arr2(n, 0);
    long long count = 0;
    for (j = 0; j < m; j++) {
        arr1[j] = nums[i++];
    }
    for (k = 0; k < n; k++) {
        arr2[k] = nums[i++];
    }
    j = k = 0;
    i = l;
    while (j < m && k < n) {
        if (arr1[j] <= arr2[k]) {
            nums[i++] = arr1[j++];
        } else {
            count += (mid - l - j + 1);
            nums[i++] = arr2[k++];
        }
    }
    while (j < m) {
        nums[i++] = arr1[j++];
    }
    while (k < n) {
        nums[i++] = arr2[k++];
    }
    return count;
}

long long mergeSort(long long nums[], int l, int r) {
    long long count = 0;
    if (l < r) {
        int mid = l + (r - l) / 2;
        count += mergeSort(nums, l, mid);
        count += mergeSort(nums, mid + 1, r);
        count += merger(nums, l, mid, r);
    }
    return count;
}

long long getInversions(long long *arr, int n) {
    long long count = mergeSort(arr, 0, n - 1);
    return count;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    long long *arr = new long long[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long inversions = getInversions(arr, n);

    cout << "Number of inversions: " << inversions << endl;

    delete[] arr;

    return 0;
}
