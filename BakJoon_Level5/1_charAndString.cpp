#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	int a;

	cin >> s;
	cin >> a;

	cout << s[a - 1];

	return 0;
}