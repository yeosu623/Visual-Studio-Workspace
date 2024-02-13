#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<uint32_t, uint32_t> a, pair<uint32_t, uint32_t> b)
{
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	uint32_t input1, input2;
	vector<pair<uint32_t, uint32_t>> v;
	for (int i = 0; i < n; i++)
	{
		cin >> input1 >> input2;
		v.push_back({ input1, input2 });
	}

	sort(v.begin(), v.end(), cmp);

	int count = 0;
	uint32_t available = 0;

	while (v.size())
	{
		pair<uint32_t, uint32_t> temp = v.back();
		v.pop_back();

		uint32_t& begin = temp.first;
		uint32_t& end = temp.second;

		if (available <= begin)
		{
			count++;
			available = end;
		}
	}

	cout << count;

	return 0;
}