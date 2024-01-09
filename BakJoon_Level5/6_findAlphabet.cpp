#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int b;
	for (int i = 0; i < 26; i++)
	{
		b = s.find((char)('a' + i));
		cout << b << ' ';
	}

	return 0;
}