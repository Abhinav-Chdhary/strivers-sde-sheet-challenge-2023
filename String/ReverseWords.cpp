string reverseWords(string s)
{
    string res = "", wrd = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == ' ')
        {
            if (wrd != "" && wrd != " ")
            {
                res = " " + wrd + res;
                wrd = "";
            }
        }
        else
            wrd += s.at(i);
    }
    res = wrd + res;
    if (res.at(0) == ' ')
        res.erase(res.begin());

    return res;
}
// Alternative soln using stack
string reverseString(string &str)
{
    stack<string> st;
    string temp = "";
    for (char c : str)
    {
        if (c == ' ')
        {
            if (temp != "")
            {
                st.push(temp);
                temp = "";
            }
        }
        else
        {
            temp += c;
        }
    }
    if (temp != "")
        st.push(temp);
    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();

        if (!st.empty())

            ans += " ";
    }
    return ans;
}