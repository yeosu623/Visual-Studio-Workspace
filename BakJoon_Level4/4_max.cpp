#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v;
	int a;
	for (int i = 0; i < 9; i++)
	{
		cin >> a;
		v.push_back(a);
	}

	int max = *max_element(v.begin(), v.end());
	cout << max << ' ';
	cout << find(v.begin(), v.end(), max) - v.begin() + 1;

	return 0;
}