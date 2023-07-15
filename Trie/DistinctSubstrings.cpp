//Can be done using trie but I'm short on time here
int distinctSubstring(string &word) {
   unordered_set<string> us;
   for(int i=0; i<word.length(); i++){
       for(int j=i; j<word.length(); j++){
           string st = word.substr(i, j-i+1);
           us.insert(st);
       }
   }
   return us.size();
}