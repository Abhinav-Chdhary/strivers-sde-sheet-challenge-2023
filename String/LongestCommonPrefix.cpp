#include <algorithm>
string longestCommonPrefix(vector<string> &arr, int n)
{
    sort(arr.begin(), arr.end());
    string first = arr[0];
    string last = arr[n - 1];

    string result = "";
    for (int i = 0; i < first.length(); i++)
    {
        if (first[i] == last[i])
            result += first[i];
        else
            break;
    }
    return result;
}
