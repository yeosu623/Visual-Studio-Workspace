#include <iostream>
#include <vector>
using namespace std;

vector<uint64_t> cache(102, -1);
uint64_t fibo(int n)
{
	cache[1] = cache[2] = cache[3] = 1;
	cache[4] = cache[5] = 2;
	for (int i = 6; i <= n; i++)
		cache[i] = cache[i - 1] + cache[i - 5];

	return cache[n];
}

int main()
{
	int trys;
	cin >> trys;

	for (int i = 0; i < trys; i++)
	{
		int n;
		cin >> n;
		cout << fibo(n) << '\n';
	}

	return 0;
}