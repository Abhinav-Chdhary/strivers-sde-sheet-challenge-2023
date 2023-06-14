int uniqueSubstrings(string s)
{
    vector<int> freq(256, -1);
        int maxCount=0, strt=-1;

        for(int i=0; i<s.length(); i++){
            char ch = s.at(i);
            if(freq[ch]>strt){
                strt = freq[ch];
            }
            freq[ch]=i;
            maxCount = max(maxCount, i-strt);
        }
    return maxCount;
}