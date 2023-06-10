long modularExponentiation(long x, long n, long m) {
	if(n==0) return 1;
	else if(n%2==0){
		return modularExponentiation((x*x)%m, n/2, m)%m;
	}
	else
		return (x*(modularExponentiation((x*x)%m, (n-1)/2, m)))%m;
}
long modularExponentiation(long x, long n, long m) {
	long ans = 1;
	while(n>0){
		if(n%2==0){
			x = (x*x)%m;
			n/=2;
		}
		else{
			ans = (ans*x)%m;
			n-=1;
		}
	}
	return ans;
}