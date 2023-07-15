//Brute O(m*n)
bool findPattern(string p, string s)
{
    int count=0, n=s.length(), m=p.length();
	for(int i=0; i<=n-m; i++){
		if(s.substr(i, m)==p)
			count++;
	}
	return count>0;
}