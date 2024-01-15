#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	int sum = 0;
	vector<int> v;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		v.push_back(a);
		sum += a;
	}

	cout << sum / 5 << '\n';
	
	sort(v.begin(), v.end());
	cout << v[2];

	return 0;
}