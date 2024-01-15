#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	vector<int> v;
	int c;
	for (int i = 0; i < a; i++)
	{
		cin >> c;
		v.push_back(c);
	}

	sort(v.begin(), v.end());
	cout << v[v.size() - b];

	return 0;
}