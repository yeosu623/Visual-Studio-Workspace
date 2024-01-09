#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (a == b && b == c)
		cout << (10000 + a * 1000);
	else if (a == b)
		cout << (1000 + a * 100);
	else if (a == c)
		cout << (1000 + a * 100);
	else if (b == c)
		cout << (1000 + b * 100);
	else
	{
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);

		int max = *max_element(v.begin(), v.end());
		
		cout << (max * 100);
	}

	return 0;
}