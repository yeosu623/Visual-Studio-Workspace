#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	vector<int> v;
	int b;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		v.push_back(b);
	}

	cout << *min_element(v.begin(), v.end()) << ' ';
	cout << *max_element(v.begin(), v.end());

	return 0;
	
}