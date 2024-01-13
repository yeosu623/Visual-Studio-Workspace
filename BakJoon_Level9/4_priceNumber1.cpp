#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
	if (n == 1) return false;

	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;

	return true;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int sum = 0;
	while (a--)
	{
		int b;
		cin >> b;

		if (isPrime(b)) sum++;
	}

	cout << sum;
}