#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << '*';
		}
		cout << '\n';
	}

	return 0;
}