#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		// c, d, l, n, s, z
		if (s[i] == 'c')
		{
			sum++;
			if (s[i + 1] == '=') { i++; continue; }
			if (s[i + 1] == '-') { i++; continue; }
		}
		else if (s[i] == 'd')
		{
			sum++;
			if (s[i + 1] == 'z' && s[i + 2] == '=') { i += 2; continue; }
			if (s[i + 1] == '-') { i++; continue; }
		}
		else if (s[i] == 'l')
		{
			sum++;
			if (s[i + 1] == 'j') { i++; continue; }
		}
		else if (s[i] == 'n')
		{
			sum++;
			if (s[i + 1] == 'j') { i++; continue; }
		}
		else if (s[i] == 's')
		{
			sum++;
			if (s[i + 1] == '=') { i++; continue; }
		}
		else if (s[i] == 'z')
		{
			sum++;
			if (s[i + 1] == '=') { i++; continue; }
		}
		else
		{
			sum++;
		}
	}

	cout << sum;

	return 0;
}