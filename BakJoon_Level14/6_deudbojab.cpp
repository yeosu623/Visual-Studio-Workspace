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

	set<string> set1;
	string s;
	for (int i = 0; i < a; i++)
	{
		cin >> s;
		set1.insert(s);
	}

	set<string> set2;
	int count = 0;
	for (int i = 0; i < b; i++)
	{
		cin >> s;
		if (set1.find(s) != set1.end())
		{
			count++;
			set2.insert(s);
		}
	}

	cout << count << '\n';
	for (const auto& n : set2)
		cout << n << '\n';

	return 0;
}