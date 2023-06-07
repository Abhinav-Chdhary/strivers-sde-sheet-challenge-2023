#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n){
    vector<vector<long long int>> pascal;
    for (int i = 1; i <= n; i++) {
      vector<long long int> temp;
      temp.push_back(1);
      long long int x = 1;
      for (int j = 1; j < i; j++) {
        x *= (i-j);
        x /= j;
        temp.push_back(x);
      }
      pascal.push_back(temp);
    }
    return pascal;
}
