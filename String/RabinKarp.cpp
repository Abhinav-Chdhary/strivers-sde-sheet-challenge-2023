//Brute force O(text.size*pattern.size)
vector<int> stringMatch(string text, string pattern) {
	int n = text.length(), k = pattern.length();
	vector<int> res;
	for(int i=0; i<=text.length()-k; i++){
		if(text.substr(i, k)==pattern)
			res.push_back(i+1);
	}
	return res;
}
//Optimal Rabin-Karp Algo
