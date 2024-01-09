#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b;

	int sum = 0;
	for (int i = 0; i < b; i++)
	{
		cin >> c >> d;

		sum = sum + (c * d);
	}

	if (a == sum) cout << "Yes";
	else cout << "No";

	return 0;
}