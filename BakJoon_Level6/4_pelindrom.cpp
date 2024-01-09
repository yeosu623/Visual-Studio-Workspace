#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int a = 1;
	for (int i = 0; i < s.length() + 1; i++)
	{
		if (s[i] != s[s.length() - 1 - i])
			a = 0;
	}

	cout << a;

	return 0;
}