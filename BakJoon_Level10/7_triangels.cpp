#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;

		if (a == b && a == c) cout << "Equilateral" << '\n';
		else if (a + b <= c || a + c <= b || b + c <= a) cout << "Invalid" << '\n';
		else
		{
			if (a == b || a == c || b == c) cout << "Isosceles" << '\n';
			else cout << "Scalene" << '\n';
		}
	}

	return 0;
}