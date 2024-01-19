#include <iostream>
using namespace std;

int fibo(int a)
{
	if (a == 0) return 0;
	if (a == 1) return 1;
	return fibo(a - 1) + fibo(a - 2);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	cout << fibo(a);

	return 0;
}