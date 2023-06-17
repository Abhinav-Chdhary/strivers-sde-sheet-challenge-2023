#include <bits/stdc++.h> 
struct Meeting{
    int start;
    int end;
    int pos;
};
static bool comp(Meeting m1, Meeting m2){
    if(m1.end<m2.end) return true;
    if(m1.end>m2.end) return false;
    if(m1.pos<m2.pos) return true;
    return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    Meeting meet[n];
    for(int i=0; i<n; i++){
        //putting values in meet data structure
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i+1;
    }
    //sort the meetings according to end time
    sort(meet, meet+n, comp);
    vector<int> res;
    //first meeting will happen anyway
    res.push_back(meet[0].pos);
    int lastTime = meet[0].end;
    for(int i=1; i<n; i++){
        //if the end time of last meeting < start of next meeting
        //we can perform it
        if(meet[i].start>lastTime){
            res.push_back(meet[i].pos);
            lastTime = meet[i].end;
        }
    }
    return res;
}