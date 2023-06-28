//Brute force + Optimal: O(nlogn)
//In brute force we stand at one index and keep checking but we don't
//need that babe
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for(int i=1; i<intervals.size(); i++){
        if(intervals[i][0]<=res.back()[1]){
            res.back()[1] = max(intervals[i][1], res.back()[1]);
        }
        else{
            res.push_back(intervals[i]);
        }
    }
    return  res;
}