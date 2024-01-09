#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b, c;
	for (int i = 1; i <= a; i++)
	{
		cin >> b >> c;
		cout << "Case #" << i << ": " << b << " + " << c << " = " << b + c << '\n';
	}

	return 0;
}