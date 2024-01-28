#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b;
	vector<int> v;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		v.push_back(b);
	}
}