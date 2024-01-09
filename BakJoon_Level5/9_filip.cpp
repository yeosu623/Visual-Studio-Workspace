#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s1, s2;
	cin >> s1 >> s2;

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] > s2[i])
		{
			cout << s1;
			break;
		}
		if (s1[i] < s2[i])
		{
			cout << s2;
			break;
		}
	}

	return 0;
}