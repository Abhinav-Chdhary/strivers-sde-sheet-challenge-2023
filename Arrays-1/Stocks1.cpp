#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int maxProfit = 0, minPrice = INT_MAX;
    for(int i=0; i<prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        int profitToday = prices[i]-minPrice;
        maxProfit = max(maxProfit, profitToday);
    }
    return maxProfit;
}