#include <iostream>
#include <vector>

using namespace std;

//Types:
//1. find (i,j) th element
//2. find nth row
//3. find pascal triangle upto nth row
vector<vector<long long int>> printPascal(int n){
    vector<vector<long long int>> pascal;
    
    for (int i = 1; i <= n; i++) {
      //temp vector for current row
      vector<long long int> temp;
      //first element is 1
      temp.push_back(1);
      long long int x = 1;
      for (int j = 1; j < i; j++) {
        //the element = ((last element inserted)*(n-column))/column
        //where n is the current row no.
        x *= (i-j);
        x /= j;
        temp.push_back(x);
      }
      pascal.push_back(temp);
    }
    return pascal;
}
int main() {
    // Example usage
    int n = 5;

    // Compute Pascal's triangle
    vector<vector<long long int>> pascal = printPascal(n);

    // Print Pascal's triangle
    cout << "Pascal's Triangle:" << endl;
    for (int i = 0; i < pascal.size(); i++) {
        for (int j = 0; j < pascal[i].size(); j++) {
            cout << pascal[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
