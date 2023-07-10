//Brute force near about O(n^3)
bool isPalin(string &str, int i, int j){
    while(i<j){
        if(str[i]!=str[j])
            return false;
        i++;
        j--;
    }
    return true;
}
string longestPalinSubstring(string str)
{
    int n = str.length();
    if(n==0) return "";
    string res = "";
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            string s = str.substr(i, j-i+1);
            if(s.length()>res.length() && isPalin(str, i, j)){
                res = s;
            }
        }
    }
    return res;
}
//Better O(n^2) by expanding
int expander(int left, int right, string &str){
    if(str.size()==0) return 0;
    while(left>=0 && right<str.length() && str[left]==str[right]){
        left--;
        right++;
    }
    return right-left-1;
}
string longestPalinSubstring(string str)
{
    if(str.length()==0) return "";
    int strt = 0, end = 0, mxlen=0;
    for(int i=0; i<str.size(); i++){
        int sub1 = expander(i, i, str);
        int sub2 = expander(i, i+1, str);
        int len = max(sub1, sub2);
        if(len > end-strt && len>mxlen){
            strt = i-((len-1)/2);
            end = i+(len/2);
            mxlen = len;
        }
    }
    return str.substr(strt, mxlen);
}
