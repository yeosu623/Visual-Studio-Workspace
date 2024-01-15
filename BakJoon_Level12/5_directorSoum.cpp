#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b = 100;
	int c = 0;
	string s;
	while (true)
	{
		b++;
		s = to_string(b);

		for (int i = 0; i < s.length() - 2; i++)
		{
			if (s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6')
			{
				c++;
				break;
			}
		}

		if (c == a) break;
	}

	cout << s;

	return 0;
}