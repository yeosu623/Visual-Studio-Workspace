#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	string s;
	set<string> set;
	for (int i = 0; i < a; i++)
	{
		cin >> s;
		set.insert(s);
	}

	int count = 0;
	for (int i = 0; i < b; i++)
	{
		cin >> s;
		if (set.find(s) != set.end()) count++;
	}

	cout << count;

	return 0;
}