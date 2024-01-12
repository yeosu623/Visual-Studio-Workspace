#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	int a;
	cin >> s;
	cin >> a;

	reverse(s.begin(), s.end());

	int sum = 0;
	int b;
	for (int i = 0; i < s.length(); i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
			b = (int)(s[i] - '0');
		else
			b = (int)(s[i] - 'A' + 10);

		for (int j = 0; j < i; j++)
		{
			b *= a;
		}

		sum += b;
	}

	cout << sum;

	return 0;
}