#include <iostream>
#include <vector>
using namespace std;

int uniqueSubstrings(string s)
{
    vector<int> freq(256, -1);
    int maxCount = 0, strt = -1;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s.at(i);
        if (freq[ch] > strt)
        {
            strt = freq[ch];
        }
        freq[ch] = i;
        maxCount = max(maxCount, i - strt);
    }
    return maxCount;
}

int main()
{
    string s = "abcabcbb"; // Example input

    int result = uniqueSubstrings(s);
    cout << "Length of the longest substring with unique characters: " << result << endl;

    return 0;
}
