#include <iostream>
#include <vector>
#include <cmath>
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
	int sum = 0;
	vector<int> v;
	vector<int> count(8001);
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		sum += b;
		count[b + 4000]++;
		v.push_back(b);
	}
	sort(v.begin(), v.end());

	int avg = round(sum / (double)v.size());
	cout << avg << '\n';
	cout << v[(0 + v.size() - 1) / 2] << '\n';

	int idx = max_element(count.begin(), count.end()) - count.begin();
	int max = count[idx];

	for (int i = idx + 1; i < 8001; i++)
		if (count[i] == max)
		{
			idx = i;
			break;
		}
	idx -= 4000;
	cout << idx << '\n';
	cout << v[v.size() - 1] - v[0] << '\n';

	return 0;
}