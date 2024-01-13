#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0) break;

		if (b % a == 0)
			cout << "factor" << '\n';
		else if (a % b == 0)
			cout << "multiple" << '\n';
		else
			cout << "neither" << '\n';
	}

	return 0;
}