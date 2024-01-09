#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	string s;
	for (int i = 0; i < a; i++)
	{
		cin >> s;
		cout << s[0] << s[s.length() - 1] << '\n';
	}

	return 0;
}