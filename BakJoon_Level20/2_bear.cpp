#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int count = 0;
	string s;
	set<string> set;
	for (int i = 0; i < a; i++)
	{
		cin >> s;
		if (s == "ENTER")
		{
			count += set.size();
			set.clear();
		}
		else
		{
			set.insert(s);
		}
	}
	count += set.size();

	cout << count;
	return 0;
}