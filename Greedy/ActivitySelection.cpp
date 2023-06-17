struct Activity{
    int start;
    int finish;
};
static bool comp(Activity &a, Activity &b){
    if(a.finish<b.finish) return true;
    return false;
}
//t.c=> O(nlogn)
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    //Create a ds to store start and finish
    Activity activ[n];
    for(int i=0; i<n; i++){
        activ[i].start = start[i];
        activ[i].finish = finish[i];
    }
    //sort them
    sort(activ, activ+n, comp);
    //we perform the first activity anyway
    int count = 1;
    int lastTime = activ[0].finish;
    for(int i=1; i<n; i++){
        //start time of next activity can coincide with finish of last
        if(activ[i].start>=lastTime){
            count++;
            lastTime = activ[i].finish;
        }
    }
    return count;
}