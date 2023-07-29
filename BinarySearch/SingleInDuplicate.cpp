#include <iostream>
#include <vector>
using namespace std;

// Brute force
int singleNonDuplicateBruteForce(vector<int> &arr)
{
	int mask = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		mask = (mask ^ arr[i]);
	}
	return mask;
}

// Binary search
int singleNonDuplicateBinarySearch(vector<int> &arr)
{
	int l = 0, r = arr.size() - 2;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (arr[mid] == arr[mid ^ 1])
			l = mid + 1;
		else
			r = mid - 1;
	}
	return arr[l];
}

int main()
{
	// Test cases
	vector<int> arr1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
	vector<int> arr2 = {3, 3, 7, 7, 10, 11, 11};
	vector<int> arr3 = {1, 1, 2, 2, 3, 3, 4, 4, 5};

	cout << "Brute force approach:" << endl;
	cout << "Result 1: " << singleNonDuplicateBruteForce(arr1) << endl;
	cout << "Result 2: " << singleNonDuplicateBruteForce(arr2) << endl;
	cout << "Result 3: " << singleNonDuplicateBruteForce(arr3) << endl;

	cout << "Binary search approach:" << endl;
	cout << "Result 1: " << singleNonDuplicateBinarySearch(arr1) << endl;
	cout << "Result 2: " << singleNonDuplicateBinarySearch(arr2) << endl;
	cout << "Result 3: " << singleNonDuplicateBinarySearch(arr3) << endl;

	return 0;
}
