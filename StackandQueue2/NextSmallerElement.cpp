#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> stk;
    for(int i=n-1; i>=0; i--){
        if(stk.empty()) ans[i] = -1;
        while(!stk.empty() && stk.top()>=arr[i]) stk.pop();
        if(!stk.empty()) ans[i] = stk.top();
        stk.push(arr[i]);
    }
    return ans;
}