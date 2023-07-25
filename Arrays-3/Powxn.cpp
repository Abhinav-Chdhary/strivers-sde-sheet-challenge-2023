#include <iostream>
using namespace std;

// Recursive implementation of modular exponentiation
long modularExponentiationRec(long x, long n, long m)
{
	if (n == 0)
		return 1;
	else if (n % 2 == 0)
	{
		// If n is even, use recursion to calculate (x^(n/2) % m)^2 % m
		return modularExponentiationRec((x * x) % m, n / 2, m) % m;
	}
	else
	{
		// If n is odd, use recursion to calculate x % m and (x^(n-1)/2 % m)^2 % m
		return (x * (modularExponentiationRec((x * x) % m, (n - 1) / 2, m))) % m;
	}
}

// Iterative implementation of modular exponentiation
long modularExponentiationIter(long x, long n, long m)
{
	long ans = 1;
	while (n > 0)
	{
		if (n % 2 == 0)
		{
			// If n is even, reduce n and square x
			x = (x * x) % m;
			n /= 2;
		}
		else
		{
			// If n is odd, multiply ans by x and reduce n by 1
			ans = (ans * x) % m;
			n -= 1;
		}
	}
	return ans;
}

int main()
{
	long x = 2;
	long n = 10;
	long m = 1000000007;

	// Using recursive implementation of modular exponentiation
	long resultRec = modularExponentiationRec(x, n, m);
	cout << "Recursive result: " << resultRec << endl;

	// Using iterative implementation of modular exponentiation
	long resultIter = modularExponentiationIter(x, n, m);
	cout << "Iterative result: " << resultIter << endl;

	return 0;
}
