//Extreme Brute Force t.c=> O(m*n)+O((m*n)log(m*n)) s.c => O(m*n)
//Brute boi
int getMedian(vector<vector<int>> &matrix)
{
    vector<int> vec;
    int m=matrix.size(), n=matrix[0].size();
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            vec.push_back(matrix[i][j]);
        }
    }
    sort(vec.begin(), vec.end());
    if((n*m)%2){
        return vec[(n*m)/2];
    }
    else{
        return (vec[(n*m)/2]+vec[(n*m)/2+1])/2;
    }
}
//Optimal Binary search O(m*logn)
int countLesser(vector<int> &vec, int tar){
    int l=0, r = vec.size()-1;
    while(l<=r){
        int mid = (l+r)>>1;
        if(vec[mid]<=tar)
            l = mid+1;
        else
            r = mid-1;
    }
    return l;
}
int getMedian(vector<vector<int>> &matrix)
{
    int low = 1, high = 1e9;
    int m = matrix.size(), n = matrix[0].size();
    while(low<=high){
        int mid = (low+high)>>1;
        int count = 0;
        for(int i=0; i<m; i++){
            count+=countLesser(matrix[i], mid);
        }
        if(count<=(n*m)/2)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}