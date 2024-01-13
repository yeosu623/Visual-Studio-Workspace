#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v;

	v.push_back(10);
	v.push_back(5);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(1);
	v.push_back(7);

	sort(v.begin(), v.end());
	
	for (const auto& n : v)
		cout << n << ' ';
}