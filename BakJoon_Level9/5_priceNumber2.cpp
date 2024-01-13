#include <iostream>
#include <vector>
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

	int a, b;
	cin >> a >> b;

	vector<int> v;
	for (int i = a; i <= b; i++)
		if (isPrime(i)) v.push_back(i);

	if (v.size())
	{
		int sum = 0;
		for (const auto& n : v)
			sum += n;

		cout << sum << '\n';
		cout << v[0];
	}
	else
		cout << -1;

	return 0;
}