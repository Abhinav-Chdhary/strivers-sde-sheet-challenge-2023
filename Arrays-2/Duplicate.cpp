#include <bits/stdc++.h>
//Brute: sort and check O(nlogn)
//Better: hash array t.c: O(n), s.c: O(n)
//Optimal: Link list style cycle detection
//t.c O(n), s.c O(1)
int findDuplicate(vector<int> &arr, int n){
	int slow, fast, temp;
	slow = fast = temp = arr[0];
	do{
		slow = arr[slow];
		fast = arr[arr[fast]];
	}while(slow!=fast);
    while (slow != temp) {
        slow = arr[slow];
        temp = arr[temp];
    }
    return temp;
}
