#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b;
	string s;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		cin >> s;

		for (int j = 0; j < s.length(); j++)
		{
			for (int k = 0; k < b; k++)
			{
				cout << s[j];
			}
		}

		cout << '\n';
	}

	return 0;
}