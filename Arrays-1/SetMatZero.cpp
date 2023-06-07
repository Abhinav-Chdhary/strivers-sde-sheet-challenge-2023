#include <iostream>
#include <vector>

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size(), m = matrix[0].size();
	int row = 1, col = 1;
	for(int i=0; i<n; i++){
		if(matrix[i][0]==0){ col=0; break;}
	}
	for(int i=0; i<m; i++){
		if(matrix[0][i]==0){ row=0; break;}
	}
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(matrix[i][j]==0){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(matrix[i][0]==0 || matrix[0][j]==0){
				matrix[i][j]=0;
			}
		}
	}
	if(col==0){
		for(int i=0; i<n; i++){
			matrix[i][0]=0;
		}
	}
	if(row==0){
		for(int i=0; i<m; i++){
			matrix[0][i]=0;
		}
	}
}