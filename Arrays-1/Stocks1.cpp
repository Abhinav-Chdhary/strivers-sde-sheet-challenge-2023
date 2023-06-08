#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maximumProfit(vector<int> &prices){
    int maxProfit = 0, minPrice = INT_MAX;
    
    for(int i=0; i<prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        int profitToday = prices[i]-minPrice;
        maxProfit = max(maxProfit, profitToday);
    }
    return maxProfit;
}

int main() {
    // Example usage
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Compute the maximum profit
    int maxProfit = maximumProfit(prices);

    // Print the result
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}