#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	vector<int> v;
	v.push_back(x);
	v.push_back(y);
	v.push_back(w - x);
	v.push_back(h - y);

	cout << *min_element(v.begin(), v.end());

	return 0;
}