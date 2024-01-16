#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n)
{
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;

	return true;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v;
	int a;
	for (int i = 0; i <= 123456 * 2; i++)
	{
		v.push_back(isPrime(i));
	}

	int b;
	while (true)
	{
		cin >> b;
		if (b == 0) break;

		int count = 0;
		for (int i = b + 1; i <= 2 * b; i++)
		{
			if (v[i]) count++;
		}

		cout << count << '\n';
	}

	return 0;
}