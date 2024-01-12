#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	int c;
	vector<char> v;
	while (a != 0)
	{
		c = a % b;
		a = a / b;

		if (c < 10)
			v.push_back('0' + c);
		else
			v.push_back('A' - 10 + c);
	}

	reverse(v.begin(), v.end());
	
	for (const auto& n : v)
		cout << n;

	return 0;
}