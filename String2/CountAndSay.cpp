//Naive approach T.C O(n^2)
string countAndSay(int n)
{
    unordered_map<string, string> um;
    um = {{"1", "11"}, {"11", "21"}, {"111", "31"}, {"2", "12"}, {"22", "22"}, {"222", "32"}, {"3", "13"}, {"33", "23"}, {"333", "33"}};
    string start = "1";
    for (int i = 0; i < n - 1; i++)
    {
        int j = 0, sz = start.size();
        string finalAns = "";
        while (j < sz)
        {
            char c = start[j];
            string s = "";
            while (j < sz && start[j] == c)
            {
                s += start[j];
                j++;
            }
            finalAns += um[s];
        }
        start = finalAns;
    }
    return start;
}