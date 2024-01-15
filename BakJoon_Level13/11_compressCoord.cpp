#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
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

	vector<int> w = v;
	sort(w.begin(), w.end());
	w.erase(unique(w.begin(), w.end()), w.end());

	for (const auto& n : v)
		cout << lower_bound(w.begin(), w.end(), n) - w.begin() << ' ';

	return 0;
}