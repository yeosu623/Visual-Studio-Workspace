#include <iostream>
#include <algorithm>
using namespace std;

uint64_t p = 1000000007;

uint64_t factorial(uint64_t n)
{
	uint64_t result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
		result %= p;
	}

	return result;
}

uint64_t power(uint64_t a, uint64_t e)
{
	if (e == 1) return a % p;

	uint64_t temp = power(a, e / 2);
	if (e % 2 == 1) return (temp * temp % p) * a % p;
	else return temp * temp % p;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	uint64_t n, k;
	cin >> n >> k;

	// 분자
	uint64_t upper = factorial(n);
	// 분모
	uint64_t lower = power(factorial(k) * factorial(n - k) % p, p - 2);

	cout << upper * lower % p;

	return 0;
}