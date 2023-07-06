// Brute O(nlogn)

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int last = arr[0];
    int cnt = 1, mxnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - 1 == last)
        {
            cnt++;
        }
        else if (arr[i] != last)
        {
            cnt = 1;
        }
        last = arr[i];
        mxnt = max(cnt, mxnt);
    }
    return mxnt;
}
// Optimal O(n)
int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int last = nums[0];
    int cnt = 1, mxnt = 1;
    unordered_set<int> myset;
    for (auto i : nums)
        myset.insert(i);

    for (int i = 0; i < n; i++)
    {
        int cur = nums[i];
        cnt = 1;
        if (!myset.count(cur - 1))
        {
            while (myset.count(cur + 1))
            {
                cur++;
                cnt++;
            }
        }
        mxnt = max(cnt, mxnt);
    }
    return mxnt;
}