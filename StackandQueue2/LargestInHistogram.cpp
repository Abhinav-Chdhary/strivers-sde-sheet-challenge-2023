 #include <bits/stdc++.h>
 int largestRectangle(vector < int > & heights) {
   int n = heights.size();
   int ans = 0;
   for(int i=0; i<n; i++){
     int minHeight = INT_MAX;
     for(int j=i; j<n; j++){
       minHeight = min(minHeight, heights[j]);
       ans = max(ans, minHeight*(j-i+1));
     }
   }
   return ans;
 }
 //optimal
  #include <bits/stdc++.h>
 int largestRectangle(vector < int > & heights) {
   int n = heights.size();
   int ans = 0;
   stack<int> st;
   vector<int> prevSmaller(n, 0), nextSmaller(n, 0);

   for(int i = n-1; i>=0; i--){
     while(!st.empty() && heights[st.top()]>=heights[i]){
       st.pop();
     }
     if(st.empty()){
       nextSmaller[i] = n-1;
     }
     else nextSmaller[i] = st.top()-1;
     st.push(i);
   }
   while(!st.empty()){
     st.pop();
   }
   for(int i=0; i<n; i++){
     while(!st.empty() && heights[st.top()]>=heights[i]){
       st.pop();
     }
     if(st.empty()) prevSmaller[i] = 0;
     else prevSmaller[i] = st.top()+1;
      st.push(i);
   }
   for(int i=0; i<n; i++){
       ans = max(ans, heights[i]*(nextSmaller[i]-prevSmaller[i]+1));
   }
   return ans;
 }