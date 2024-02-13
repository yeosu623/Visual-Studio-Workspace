#include <iostream>
#include <cstring>
using namespace std;

// 2147483647
#define CACHE_SIZE 1000000
uint64_t cache[CACHE_SIZE];

uint64_t recursion(uint64_t a, uint64_t b, uint64_t c)
{
	// cache
	if (b < CACHE_SIZE)
		if (cache[b] != -1) return cache[b];

	// non-cache
	if (b == 1) return cache[1] = a % c;
	else if (b == 2) return cache[2] = ((a % c) * (a % c)) % c;
	else
	{
		if (b < CACHE_SIZE)
		{
			if (b % 2 == 0) return cache[b] = (recursion(a, b / 2, c) * recursion(a, b / 2, c)) % c;
			else if (b % 2 == 1) return cache[b] = (recursion(a, b / 2, c) * recursion(a, b / 2 + 1, c)) % c;
		}
		else
		{
			if (b % 2 == 0) return (recursion(a, b / 2, c) * recursion(a, b / 2, c)) % c;
			else if (b % 2 == 1) return (recursion(a, b / 2, c) * recursion(a, b / 2 + 1, c)) % c;
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	uint64_t a, b, c;
	cin >> a >> b >> c;

	memset(cache, -1, sizeof(cache));
	cout << recursion(a, b, c);

	return 0;
}