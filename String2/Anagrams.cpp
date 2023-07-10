//Brute force sort and check O(nlogn)
bool areAnagram(string &str1, string &str2){
    string s1 = str1, s2 = str2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1==s2;
}
//Hashing O(n)
bool areAnagram(string &str1, string &str2){
    if(str1.length()!=str2.length()) return false;
    vector<int> freq(26, 0);
    for(int i=0; i<str1.length(); i++){
        freq[str1[i]-'a']++;
        freq[str2[i]-'a']--;
    }
    for(int i=0; i<26; i++){
        if(freq[i]!=0) return false;
    }
    return true;
}