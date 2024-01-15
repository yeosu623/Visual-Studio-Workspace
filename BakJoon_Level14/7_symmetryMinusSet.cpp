#include <iostream>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	int c;
	set<int> set1;
	for (int i = 0; i < a; i++)
	{
		cin >> c;
		set1.insert(c);
	}

	set<int> set2;
	for (int i = 0; i < b; i++)
	{
		cin >> c;
		set2.insert(c);
	}

	set<int> set1_copy = set1;

	for (const auto& n : set2)
		set1.erase(n);

	for (const auto& n : set1_copy)
		set2.erase(n);

	cout << set1.size() + set2.size();

	return 0;
}