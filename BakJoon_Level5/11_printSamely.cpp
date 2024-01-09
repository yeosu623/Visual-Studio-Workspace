#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	while (getline(cin, s))
	{
		cout << s << '\n';
	}

	return 0;
}