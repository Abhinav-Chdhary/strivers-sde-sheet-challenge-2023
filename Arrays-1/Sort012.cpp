#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int l, m, h;
   l=m=0; h = n-1;
   while(m<=h){
      if(arr[m]==0){
         swap(arr[m], arr[l]);
         l++; m++;
      }
      else if(arr[m]==2){
         swap(arr[m], arr[h]);
         h--;
      }
      else{
         m++;
      }
   }
}