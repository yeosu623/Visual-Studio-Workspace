#include <iostream>
#include <vector>
using namespace std;

vector<short> cache(1000001, -1);
int fibo(int n)
{
	cache[1] = 1;
	cache[2] = 2;
	for (int i = 3; i <= n; i++)
		cache[i] = (cache[i - 1] + cache[i - 2]) % 15746;

	return cache[n];
}

int main()
{
	int n;
	cin >> n;

	cout << fibo(n);

	return 0;
}