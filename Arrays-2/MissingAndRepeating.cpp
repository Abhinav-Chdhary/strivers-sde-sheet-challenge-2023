#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Extreme Brute Force (O(n^2))
pair<int, int> missingAndRepeating_BruteForce(vector<int> &arr, int n)
{
    pair<int, int> ans = {-1, -1};
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if ((i + 1) == arr[j])
                cnt++;
        }
        if (cnt == 2)
            ans.second = i + 1;
        if (cnt == 0)
            ans.first = i + 1;
    }
    return ans;
}

// Optimal with extra space (T.C = O(n), S.C = O(n))
pair<int, int> missingAndRepeating_ExtraSpace(vector<int> &arr, int n)
{
    vector<int> freq(n, 0);
    pair<int, int> ans = {-1, -1};
    for (int i = 0; i < n; i++) {
        freq[arr[i] - 1]++;
    }
    for (int i = 0; i < n; i++) {
        if (freq[i] == 2)
            ans.second = i + 1;
        if (freq[i] == 0)
            ans.first = i + 1;
    }
    return ans;
}

// Optimal using mathematics
pair<int, int> missingAndRepeating_Math(vector<int> &arr, int n)
{
    // missing, repeating
    pair<int, int> ans = {-1, -1};
    // sum till n natural numbers
    long long Sn = (n * (n + 1)) / 2;
    // sum till square of n natural numbers
    long long Sn2 = (n * (n + 1) * (2 * n + 1)) / 6;
    // For similar sums of given array
    long long S = 0, S2 = 0;

    for (int i = 0; i < n; i++) {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }
    // ans.repeating - ans.missing
    int val1 = S - Sn;
    // (ans.repeating - ans.missing)^2
    int val2 = S2 - Sn2;
    // ans.repeating + ans.missing
    int val3 = val2 / val1;
    // ans.repeating
    ans.second = (val3 + val1) / 2;
    // ans.missing
    ans.first = ans.second - val1;

    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<int, int> result_brute = missingAndRepeating_BruteForce(arr, n);
    pair<int, int> result_extra_space = missingAndRepeating_ExtraSpace(arr, n);
    pair<int, int> result_math = missingAndRepeating_Math(arr, n);

    cout << "Missing and Repeating elements (Brute Force): ";
    cout << "Missing = " << result_brute.first << ", Repeating = " << result_brute.second << endl;

    cout << "Missing and Repeating elements (Extra Space): ";
    cout << "Missing = " << result_extra_space.first << ", Repeating = " << result_extra_space.second << endl;

    cout << "Missing and Repeating elements (Math): ";
    cout << "Missing = " << result_math.first << ", Repeating = " << result_math.second << endl;

    return 0;
}
