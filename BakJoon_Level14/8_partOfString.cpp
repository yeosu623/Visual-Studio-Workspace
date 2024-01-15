#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	
	set<string> set;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 1; j <= s.length() - i; j++)
		{
			set.insert(s.substr(i, j));
		}
	}

	cout << set.size();

	return 0;
}