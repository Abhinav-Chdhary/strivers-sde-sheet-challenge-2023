#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    stack<int> stk;
    int n = price.size();
    vector<int> spans(n, -1);
    for(int i=0; i<n; i++){
        while(!stk.empty() && price[stk.top()]<=price[i]){
            stk.pop();
        }
        if(stk.empty()){
            spans[i] = 0;
        }
        else spans[i] = stk.top()+1;
        stk.push(i);
    }
    vector<int> ans(n, -1);
    for(int i=0; i<n; i++){
        ans[i] = i-spans[i]+1;
    }
    return ans;
}