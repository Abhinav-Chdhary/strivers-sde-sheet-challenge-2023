void generator(vector<string>& res, string s, int ind){
    if(ind>=s.size()){
        res.push_back(s);
        return;
    }
    for(int i = ind; i<s.size(); i++){
        swap(s[ind], s[i]);
        generator(res, s, ind+1);
        swap(s[ind], s[i]);
    }
}
vector<string> findPermutations(string &s) {
    vector<string> result;
    generator(result, s, 0);
    return result;
}