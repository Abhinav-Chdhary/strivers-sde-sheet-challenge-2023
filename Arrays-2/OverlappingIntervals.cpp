//Brute force + Optimal: O(nlogn)
//In brute force we stand at one index and keep checking but we don't
//need that babe
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    // Sort the intervals based on the start time
    sort(intervals.begin(), intervals.end());

    // Create a result vector to store the merged intervals
    vector<vector<int>> res;

    // Push the first interval to the result vector
    res.push_back(intervals[0]);

    // Merge the intervals
    for (int i = 1; i < intervals.size(); i++) {
        // If the current interval overlaps with the last interval in the result vector
        if (intervals[i][0] <= res.back()[1]) {
            // Merge the intervals by updating the end time of the last interval
            res.back()[1] = max(intervals[i][1], res.back()[1]);
        }
        else {
            // The current interval does not overlap with the last interval in the result vector,
            // so push it to the result vector
            res.push_back(intervals[i]);
        }
    }

    // Return the merged intervals
    return res;
}

int main() {
    // Create sample intervals
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    // Merge the intervals
    vector<vector<int>> merged = mergeIntervals(intervals);

    // Print the merged intervals
    for (auto interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}
