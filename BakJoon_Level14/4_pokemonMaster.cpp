#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	map<string, string> map;

	string s;
	for (int i = 1; i < a+1; i++)
	{
		cin >> s;
		map.insert({ s, to_string(i) });
		map.insert({ to_string(i), s });
	}

	for (int i = 0; i < b; i++)
	{
		cin >> s;
		cout << map[s] << '\n';
	}

	return 0;
}