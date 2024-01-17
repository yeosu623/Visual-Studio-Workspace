#include <iostream>
using namespace std;

int factorial(int n)
{
	int a = 1;
	for (int i = 1; i <= n; i++)
	{
		a *= i;
	}
	return a;
}

int bc(int n, int k)
{
	return factorial(n) / factorial(k) / factorial(n - k);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	
	cout << bc(n, k);

	return 0;
}