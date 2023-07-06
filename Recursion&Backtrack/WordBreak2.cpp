#include <bits/stdc++.h> 
void generator(int ind, string &s, unordered_map<string, bool> &ump, string temp, vector<string> &ans){
    if(ind>=s.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=ind; i<s.size(); i++){
        if (ump[s.substr(ind, i - ind + 1)]) {
            temp.append(s.substr(ind, i - ind + 1));
            temp+=" ";
            generator(i+1, s, ump, temp, ans);
            int sz = temp.size();
            temp = temp.substr(0, sz-(i-ind+2));
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_map<string, bool> ump;
    for(auto it: dictionary) ump[it] = true;
    vector<string> ans;
    generator(0, s, ump, "", ans);
    return ans;
}