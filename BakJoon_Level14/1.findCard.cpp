#include <iostream>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b;
	set<int> set;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		set.insert(b);
	}

	int c;
	cin >> c;

	int d;
	for (int i = 0; i < c; i++)
	{
		cin >> d;
		if (set.find(d) != set.end()) cout << 1 << ' ';
		else cout << 0 << ' ';
	}

	return 0;
}