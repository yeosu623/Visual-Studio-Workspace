#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(unsigned int n)
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

	int a;
	cin >> a;

	unsigned int b;
	for (int i = 0; i < a; i++)
	{
		cin >> b;

		while (1)
		{
			if (isPrime(b))
			{
				cout << b << '\n';
				break;
			}
			else b++;
		}
	}

	return 0;
}