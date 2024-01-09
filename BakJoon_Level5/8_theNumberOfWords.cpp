#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	getline(cin, s);

	int sum = 0;
	int flag = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ' && flag == 0)
		{
			flag = 1;
			sum++;
		}
		if (s[i] == ' ') flag = 0;
	}

	cout << sum;

	return 0;
}