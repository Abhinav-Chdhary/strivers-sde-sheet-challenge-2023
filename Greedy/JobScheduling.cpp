static bool cmp(vector<int> &a, vector<int> &b){
    return a[1]>b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), cmp);
    vector<int> slots(3001, 0);
    int profit = 0;
    for(int i=0; i<jobs.size(); i++){
        if(!slots[jobs[i][0]]){
            profit+=jobs[i][1];
            slots[jobs[i][0]] = 1;
        }
        else{
            int j = jobs[i][0];
            while(j>0){
                if(!slots[j]){
                    profit+=jobs[i][1];
                    slots[j] = 1;
                    break;
                }
                j--;
            }
        }
    }
    return profit;
}