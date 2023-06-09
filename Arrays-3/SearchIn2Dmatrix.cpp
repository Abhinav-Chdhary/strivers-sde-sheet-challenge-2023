bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int l=0, r= m*n-1;

        while(l<=r){
            int mid = l+(r-l)/2;
            int val = mat[mid/n][mid%n];
            if(val==target)
                return true;
            else if(val>target)
                r = mid-1;
            else
                l = mid+1;
        }
        return false;
}