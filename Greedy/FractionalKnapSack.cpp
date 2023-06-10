#include <bits/stdc++.h> 
bool compareRatio(const pair<int, int>& a, const pair<int, int>& b) {
    double ratioA = static_cast<double>(a.second)/(a.first);
    double ratioB = static_cast<double>(b.second)/(b.first);

    return ratioA > ratioB;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), compareRatio);
    double res = 0.0;
    for(int i=0; i<n && w>0; i++){
        if(items[i].first<w){
            res += items[i].second;
            w-=items[i].first;
        }
        else{
            res += ((double)items[i].second/(double)items[i].first)*w;
            break;
        }
    }
    return res;
}