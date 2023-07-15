//Brute O(m*n) time
int zAlgorithm(string s, string p, int n, int m)
{
	int count=0;
	for(int i=0; i<=n-m; i++){
		if(s.substr(i, m)==p)
			count++;
	}
	return count;
}