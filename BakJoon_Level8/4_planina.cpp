#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b = 2;
	for (int i = 0; i < a; i++)
	{
		b = b * 2 - 1;
	}

	cout << b * b;

	return 0;
}