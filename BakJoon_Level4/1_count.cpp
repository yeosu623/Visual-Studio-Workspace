#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a;

	vector<int> v;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		v.push_back(b);
	}

	cin >> c;
	cout << count(v.begin(), v.end(), c);

	return 0;
}